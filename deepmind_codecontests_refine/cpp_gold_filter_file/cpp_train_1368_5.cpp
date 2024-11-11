#include <bits/stdc++.h>
using namespace std;
int counts[1000000 + 2];
int Solve(int pos, int p0, int p1, int p2, int m) {
  if (pos > m) return 0;
  int ans = 0;
  if (p1 >= 1 && p2 >= 1 && p0 >= 1) {
    ans = max(ans, 1 + Solve(pos, p0 - 1, p1 - 1, p2 - 1, m));
  }
  if (p0 >= 3) {
    ans = max(ans, 1 + Solve(pos, p0 - 3, p1, p2, m));
  }
  ans = max(ans, Solve(pos + 1, counts[pos + 1], p0, p1, m));
  return ans;
}
vector<int> dp[1000000 + 2];
int GetC(int pos) {
  if (pos < 1) return 0;
  return counts[pos];
}
int GetV(int p0, int p1, int p2, int pos) {
  int v = p0 * (GetC(pos - 1) + 1) * (GetC(pos - 2) + 1) +
          p1 * (GetC(pos - 2) + 1) + p2;
  if (v >= dp[pos].size()) {
    printf("err\n");
    exit(-1);
  }
  return v;
}
int Solve(int m) {
  for (int pos = m; pos >= 1; pos--) {
    dp[pos].resize((GetC(pos) + 1) * (GetC(pos - 1) + 1) * (GetC(pos - 2) + 1));
    int c0 = GetC(pos);
    int c1 = GetC(pos - 1);
    int c2 = GetC(pos - 2);
    for (int p0 = 0; p0 <= c0; p0++) {
      for (int p1 = 0; p1 <= c1; p1++) {
        for (int p2 = 0; p2 <= c2; p2++) {
          int ans = 0;
          if (p1 >= 1 && p2 >= 1 && p0 >= 1) {
            ans = max(ans, 1 + dp[pos][GetV(p0 - 1, p1 - 1, p2 - 1, pos)]);
          }
          if (p0 >= 3) {
            ans = max(ans, 1 + dp[pos][GetV(p0 - 3, p1, p2, pos)]);
          }
          if (pos + 1 <= m) {
            ans = max(ans, dp[pos + 1][GetV(counts[pos + 1], p0, p1, pos + 1)]);
          }
          dp[pos][GetV(p0, p1, p2, pos)] = ans;
        }
      }
    }
  }
  return dp[1][GetV(counts[1], 0, 0, 1)];
}
void Process(int x) {
  int orig = x;
  int ans = 0;
  if (x > 3) {
    ans = (x - 3) / 3;
    x %= 3;
    x += 3;
  }
  printf("orig=%d :: %d,%d\n", orig, x, ans);
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    counts[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    counts[x]++;
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int extra = counts[i] - 5;
    if (extra > 0) {
      ans += extra / 3;
      extra %= 3;
      counts[i] = 5 + extra;
    }
  }
  cout << ans + Solve(m) << endl;
}
