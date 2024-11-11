#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
pair<int, int> a[N], b[N];
pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
long long operator*(const pair<int, int> &a, const pair<int, int> &b) {
  return 1LL * a.first * b.second - 1LL * a.second * b.first;
}
void shift(pair<int, int> a[], int n) {
  rotate(a + 1, max_element(a + 1, a + n + 1), a + n + 1);
}
pair<int, int> c[N];
int cl;
void merge(pair<int, int> a[], pair<int, int> b[], int &la, int lb) {
  c[cl = 1] = a[1] + b[1];
  for (int i = 1, j = 1;;) {
    pair<int, int> A = a[i % la + 1] - a[i], B = b[j % lb + 1] - b[j], second;
    if (A * B >= 0) {
      i = i % la + 1, second = a[i] + b[j];
    } else {
      j = j % lb + 1, second = a[i] + b[j];
    }
    if (cl >= 2 && (second - c[cl]) * (c[cl] - c[cl - 1]) == 0) cl--;
    c[++cl] = second;
    if (i == 1 && j == 1) break;
  }
  cl--, la = cl;
  memcpy(a + 1, c + 1, cl * sizeof(c[0]));
}
int m;
set<pair<int, int> > t1, t2;
void init() {
  int ed = min_element(a + 1, a + m + 1) - a;
  for (int i = 1; i <= ed; i++) t1.insert(a[i]);
  for (int i = ed; i <= m; i++) t2.insert(make_pair(a[i].first, -a[i].second));
  if (a[m].first != a[1].first) t2.insert(make_pair(a[1].first, -a[1].second));
}
const int inf = 2e9;
inline bool chk(set<pair<int, int> > &s, int first, int second) {
  set<pair<int, int> >::iterator it = s.lower_bound(make_pair(first, second));
  if (it == s.end()) return false;
  if (it->first == first) return it->second >= second;
  if (it == s.begin()) return false;
  set<pair<int, int> >::iterator t = it;
  t--;
  pair<int, int> L = *t, R = *it, cur = make_pair(first, second);
  if ((cur - L) * (R - L) >= 0)
    return true;
  else
    return false;
}
bool check(int first, int second) {
  if (chk(t1, first, second) && chk(t2, first, -second))
    return true;
  else
    return false;
}
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &a[i].first, &a[i].second);
  shift(a, m);
  for (int t = 0; t < 2; t++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &b[i].first, &b[i].second);
    shift(b, n);
    merge(a, b, m, n);
  }
  init();
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int first, second;
    scanf("%d%d", &first, &second);
    if (check(first * 3, second * 3))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
