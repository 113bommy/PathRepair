#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
inline void gn(int &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
inline void gn(long long &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
inline void gn(double &first) { scanf("%lf", &first); }
inline void newline() { putchar('\n'); }
inline void sp() { putchar(' '); }
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
long long B[2555][2555];
int ID[2555][2555];
int N, M;
int update(int u, int v, long long val) {
  for (int i = u; i < N; i += i & -i)
    for (int j = v; j < M; j += j & -j) B[i][j] += val;
}
long long calc(int u, int v) {
  long long ans = 0;
  for (int i = u; i; i -= i & -i)
    for (int j = v; j; j -= j & -j) ans += B[i][j];
  return ans;
}
int update(int u, int v, int uu, int vv, long long val) {
  if (u > uu) swap(u, uu);
  if (v > vv) swap(v, vv);
  update(u, v, val);
  update(uu + 1, v, -val);
  update(u, vv + 1, -val);
  update(uu + 1, vv + 1, val);
}
int main() {
  int q;
  int t, c1, r1, c2, r2, id = 0;
  cin >> N >> M >> q;
  while (q--) {
    gn(t), gn(r1), gn(c1), gn(r2), gn(c2);
    if (t == 1)
      ID[r1][c1] = ++id,
      update(r1, c1, r2, c2, (1LL * (ID[r1][c1]) * (ID[r1][c1])));
    if (t == 2) update(r1, c1, r2, c2, -(1LL * (ID[r1][c1]) * (ID[r1][c1])));
    if (t == 3) {
      long long u1 = calc(r1, c1);
      long long u2 = calc(r2, c2);
      if (u1 == u2)
        puts("Yes");
      else
        puts("No");
    }
  }
  return 0;
}
