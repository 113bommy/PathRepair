#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <typename T>
inline bool remin(T& c, const T& n) {
  if (c > n) {
    c = n;
    return 1;
  }
  return 0;
}
template <typename T>
inline bool remax(T& c, const T& n) {
  if (c < n) {
    c = n;
    return 1;
  }
  return 0;
}
int _in;
int in() {
  scanf("%d", &_in);
  return _in;
}
const int N = 2e5;
int heaven[N], n, m, hsz = 0;
int hell(int a) { return lower_bound(heaven, heaven + hsz, a) - heaven; }
double push[4 * N];
void _build(int from, int to, int v) {
  if (from + 1 == to)
    push[v] = 0;
  else {
    int mid = (from + to) / 2;
    _build(from, mid, v * 2);
    _build(mid, to, v * 2 + 1);
    push[v] = 1;
  }
}
void _alter(int qfrom, int from, int to, int v, double val) {
  if (from + 1 == to)
    push[v] += val;
  else {
    int mid = (from + to) / 2;
    qfrom < mid ? _alter(qfrom, from, mid, v * 2, val)
                : _alter(qfrom, mid, to, v * 2 + 1, val);
  }
}
void alter(int qfrom, int val) { _alter(qfrom, 0, hsz, 1, val); }
void _seg(int qfrom, int qto, int from, int to, int v, double prob) {
  if (qfrom < qto) {
    if (qfrom == from && qto == to)
      push[v] *= prob;
    else {
      int mid = (from + to) / 2;
      _seg(qfrom, min(qto, mid), from, mid, v * 2, prob);
      _seg(max(qfrom, mid), qto, mid, to, v * 2 + 1, prob);
    }
  }
}
void seg(int qfrom, int qto, double prob) {
  _seg(max(qfrom, 0), min(qto, hsz), 0, hsz, 1, prob);
}
double _dry(int from, int to, int v) {
  if (from + 1 == to)
    return push[v];
  else {
    int mid = (from + to) / 2;
    return (_dry(from, mid, v * 2) + _dry(mid, to, v * 2 + 1)) * push[v];
  }
}
stack<int> input;
int main() {
  n = in();
  m = in();
  int i, j, h, l, r, p;
  for ((i) = (0); (i) < (n); ++(i)) {
    input.push(heaven[hsz++] = in());
    input.push(in());
    input.push(in());
    input.push(in());
  }
  for ((i) = (0); (i) < (m); ++(i)) {
    input.push(heaven[hsz++] = in());
    input.push(in());
  }
  sort(heaven, heaven + hsz);
  hsz = unique(heaven, heaven + hsz) - heaven;
  _build(0, hsz, 1);
  for ((i) = (0); (i) < (m); ++(i)) {
    p = input.top();
    input.pop();
    j = input.top();
    input.pop();
    j = hell(j);
    alter(j, p);
  }
  for ((i) = (0); (i) < (n); ++(i)) {
    r = input.top();
    input.pop();
    l = input.top();
    input.pop();
    h = input.top();
    input.pop();
    p = input.top();
    j = hell(p);
    input.pop();
    seg(hell(p - h), j, double(100 - l) / 100.0);
    seg(j + 1, hell(p + h) + 1, double(100 - r) / 100.0);
  }
  printf("%lf\n", _dry(0, hsz, 1));
  return 0;
}
