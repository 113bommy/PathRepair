#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 50;
int sum[M];
int p[M];
int n;
int fen[M];
int Get(int p) {
  int u = p;
  int ans = 0;
  for (; p > 0; p -= p & -p) ans += fen[p];
  for (u++; u < M; u += u & -u) fen[u]++;
  return ans;
}
int get(int p) {
  int cur = 0;
  for (int i = 16; ~i; i--) {
    int d = cur + (1 << i);
    if (fen[d] <= p) p -= fen[d], cur = d;
  }
  int u = cur;
  for (u++; u < M; u += u & -u) fen[u]--;
  return cur;
}
void solve() {
  memset(fen, 0, sizeof fen);
  for (int i = 0; i < n; i++) sum[i] += p[i] - Get(p[i]);
}
int32_t main() {
  scanf("%d", &n);
  int t = 2;
  while (t--) {
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    solve();
  }
  int sb = 0;
  for (int i = n - 1; ~i; i--) {
    sum[i] += sb;
    int k = sum[i] % (n - i);
    sb = (sum[i] - k) / (n - i);
    sum[i] = k;
  }
  for (int i = 1; i < M; i++) fen[i] = i & -i;
  for (int i = 0; i < n; i++) printf("%d ", get(sum[i]));
  return printf("\n"), 0;
}
