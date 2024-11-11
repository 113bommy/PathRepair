#include <bits/stdc++.h>
using namespace std;
bitset<2005> dp[1 << 16];
int a[2005], lg[1 << 16], b[2005], sum, n, k;
struct hh {
  int p, w;
  bool operator<(hh x) const { return w < x.w; }
};
priority_queue<hh> q;
void dfs(int x, int w) {
  if (!x) return;
  for (; w * k <= sum && dp[x][w * k]; w *= k)
    for (int i = x; i; i -= i & -i) b[lg[i & -i] + 1]++;
  for (int i = x; i; i -= i & -i) {
    int v = lg[i & -i] + 1;
    if (w >= a[v] && dp[x - (i & -i)][w - a[v]]) {
      dfs(x - (i & -i), w - a[v]);
      return;
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum += a[i];
  int len = 1 << n;
  dp[0][0] = 1;
  for (int i = 2; i < len; ++i) lg[i] = lg[i / 2] + 1;
  for (int i = 1; i < len; ++i) {
    for (int j = i; j; j -= j & -j) {
      int t = lg[j & -j] + 1;
      dp[i] |= dp[i - (j & -j)] << a[t];
    }
    for (int j = sum / k; j >= 1; --j)
      if (dp[i][j * k]) dp[i][j] = 1;
  }
  if (!dp[len - 1][1])
    puts("NO");
  else {
    puts("YES");
    dfs(len - 1, 1);
    for (int i = 1; i <= n; ++i) q.push((hh){a[i], b[i]});
    while (q.size() > 1) {
      hh p1 = q.top();
      q.pop();
      hh p2 = q.top();
      q.pop();
      printf("%d %d\n", p1.p, p2.p);
      p1.p += p2.p;
      while (p1.p % k == 0) p1.p /= k, p1.w--;
      q.push(p1);
    }
  }
}
