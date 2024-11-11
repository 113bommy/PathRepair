#include <bits/stdc++.h>
using namespace std;
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < 48) c = getchar();
  while (c > 47) x = x * 10 + (c ^ 48), c = getchar();
  return x;
}
const int maxn = 10010, base = 1e7 + 19, P = 1e9 + 7;
int n, m, q, tot, pw[1010];
int st[35000], ed[35000];
struct node {
  int val, cost;
} A[35000];
int dp[15][1010];
vector<int> vec[maxn << 2];
void add(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) return vec[k].push_back(x), void();
  if (ql <= ((l + r) >> 1)) add(k << 1, l, ((l + r) >> 1), ql, qr, x);
  if (qr > ((l + r) >> 1)) add(k << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr, x);
}
void divide(int k, int l, int r, int dep) {
  memcpy(dp[dep], dp[dep - 1], (m + 1) << 2);
  for (int pos : vec[k]) {
    int val = A[pos].val, cost = A[pos].cost;
    for (int i = (m), iend = (cost); i >= iend; --i)
      chkmax(dp[dep][i], dp[dep][i - cost] + val);
  }
  if (l == r) {
    int res = 0;
    for (int i = (1), iend = (m); i <= iend; ++i)
      res = (res + 1ll * dp[dep][i] * pw[i - 1]) % P;
    printf("%d\n", res);
    return;
  }
  divide(k << 1, l, ((l + r) >> 1), dep + 1),
      divide(k << 1 | 1, ((l + r) >> 1) + 1, r, dep + 1);
}
int main() {
  pw[0] = 1;
  for (int i = (1), iend = (1000); i <= iend; ++i)
    pw[i] = 1ll * base * pw[i - 1] % P;
  cin >> n >> m;
  for (int i = (1), iend = (n); i <= iend; ++i) {
    A[i].val = read(), A[i].cost = read(), st[i] = 1;
  }
  memset(ed, 0x3f, sizeof ed);
  tot = n;
  cin >> q;
  int now = 0;
  for (int i = (1), iend = (q); i <= iend; ++i) {
    int op = read();
    if (op == 1) {
      tot++, A[tot].val = read(), A[tot].cost = read(), st[tot] = now + 1;
    } else if (op == 2) {
      ed[read()] = now;
    } else {
      now++;
    }
  }
  for (int i = (1), iend = (tot); i <= iend; ++i)
    if (st[i] <= ed[i]) {
      add(1, 1, now, st[i], ed[i], i);
    }
  divide(1, 1, now, 1);
  return 0;
}
