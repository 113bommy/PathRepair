#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2005;
constexpr int MAXINT = 1073741823;
string s[MAXN];
int lcp[MAXN];
int counter;
int dp[MAXN * 2][MAXN];
int solve(int from, int to) {
  if (from == to) return counter++;
  int id = counter++, index = from, left, right;
  for (int i = from; i < to; i++)
    if (lcp[i] < lcp[index]) index = i;
  left = solve(from, index);
  right = solve(index + 1, to);
  for (int i = 0; i <= index - from + 1; i++)
    for (int j = 0; j <= to - index; j++)
      dp[id][i + j] =
          max(dp[id][i + j], dp[left][i] + dp[right][j] + lcp[index] * i * j);
  return id;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s, s + n);
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < min(s[i].size(), s[i + 1].size()); j++)
      if (s[i][j] == s[i + 1][j])
        lcp[i]++;
      else
        break;
  solve(0, n - 1);
  cout << dp[0][k];
  return 0;
}
