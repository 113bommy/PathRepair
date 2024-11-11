#include <bits/stdc++.h>
using namespace std;
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;
template <typename T>
inline void read(T &x) {
  char ch, t = 0;
  x = 0;
  while (!isdigit(ch = (iS == iT
                            ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)))
    t |= ch == '-';
  while (isdigit(ch))
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
  x = t ? -x : x;
}
inline int read_int() {
  int x;
  return read(x), x;
}
inline long long read_ll() {
  long long x;
  return read(x), x;
}
template <typename T>
inline void chkmin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void chkmax(T &a, T b) {
  a = a > b ? a : b;
}
inline long long Qh(int x, int y, int z) {
  printf("1 %d %d %d\n", x, y, z), fflush(stdout);
  long long s;
  scanf("%lld", &s);
  return s;
}
inline int Q(int x, int y, int z) {
  printf("2 %d %d %d\n", x, y, z), fflush(stdout);
  int s;
  scanf("%d", &s);
  return s;
}
vector<int> P[4];
int bel[1010];
long long h[1010];
inline bool cmp0(int a, int b) { return h[a] > h[b]; }
inline bool cmp1(int a, int b) { return h[a] < h[b]; }
int main() {
  int n;
  scanf("%d", &n);
  int mx[2] = {0, 0};
  for (int i = 3; i <= n; i++) bel[i] = Q(1, 2, i) < 0;
  for (int i = 3; i <= n; i++) {
    h[i] = Qh(1, 2, i);
    if (h[i] > h[mx[bel[i]]]) mx[bel[i]] = i;
  }
  for (int i = 3; i <= n; i++) {
    if (i == mx[bel[i]]) continue;
    int t = Q(1, mx[bel[i]], i) < 0;
    P[bel[i] << 1 | t].push_back(i);
  }
  for (int i = 0; i < 4; i++)
    sort(P[i].begin(), P[i].end(), i & 1 ? cmp1 : cmp0);
  printf("0 1");
  for (auto u : P[3]) printf(" %d", u);
  if (mx[1]) printf(" %d", mx[1]);
  for (auto u : P[2]) printf(" %d", u);
  printf(" 2");
  for (auto u : P[1]) printf(" %d", u);
  if (mx[0]) printf(" %d", mx[0]);
  for (auto u : P[0]) printf(" %d", u);
  puts(""), fflush(stdout);
  return 0;
}
