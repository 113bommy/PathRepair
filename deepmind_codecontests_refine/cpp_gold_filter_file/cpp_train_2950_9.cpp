#include <bits/stdc++.h>
using namespace std;
template <class T>
void clear(T &x) {
  T t;
  x.swap(t);
}
template <class T>
void miz(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void maz(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
unsigned HASH(const char *p) {
  unsigned r = 0;
  while (*p) r = r * 129 + *p++;
  return r;
}
struct Lem {
  int m, v, i;
  bool operator<(const Lem &q) const { return m < q.m || m == q.m && v < q.v; }
};
const int NMAX = 100000;
Lem lem[NMAX];
int main() {
  int N, K;
  vector<int> ans, tmp;
  int i, j;
  scanf("%d%d%*d", &N, &K);
  for (i = 0; i < N; i++) scanf("%d", &lem[i].m);
  for (i = 0; i < N; i++) scanf("%d", &lem[i].v);
  for (i = 0; i < N; i++) lem[i].i = i + 1;
  sort(lem, lem + N);
  double _l = 0, _r = N + 1, _m;
  for (int z = 0; z < 100; z++) {
    _m = (_l + _r) / 2;
    tmp.clear();
    j = 1;
    for (i = 0; i < N; i++) {
      if (_m * lem[i].v >= j) {
        tmp.push_back(lem[i].i);
        if (j++ == K) break;
      }
    }
    if (j > K) {
      ans = tmp;
      _r = _m;
    } else {
      _l = _m;
    }
  }
  for (i = 0; i < K; i++) {
    printf("%d", ans[i]);
    putchar(i + 1 != K ? ' ' : '\n');
  }
  return 0;
}
