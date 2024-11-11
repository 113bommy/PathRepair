#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class S>
ostream &operator<<(ostream &o, const pair<T, S> &p) {
  return o << '(' << p.first << ", " << p.second << ')';
}
template <template <class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream &>::type operator<<(
    ostream &o, T<A...> V) {
  o << '[';
  for (auto a : V) o << a << ", ";
  return o << ']';
}
pair<int, pair<char, char>> dp[510][27][27];
int n, m, cts[510][2][26];
int r(int i, int c1, int c2) {
  if (i == n) return 0;
  if (dp[i][c1][c2].first != INT_MAX) return dp[i][c1][c2].first;
  for (int a = 0; a < 26; a++)
    for (int b = 0; b < 26; b++)
      if (a != c1 && b != c2 && a != b) {
        int cost = m - cts[i][0][a] - cts[i][1][b] + r(i + 1, a, b);
        if (cost < dp[i][c1][c2].first)
          dp[i][c1][c2] = {cost, {a + 'a', b + 'a'}};
      }
  return dp[i][c1][c2].first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i < n; i++) {
    char c;
    for (int j = 0; j < m; j++) {
      scanf("%c", &c);
      cts[i][j & 1][c - 'a']++;
    }
    scanf("%c", &c);
  }
  for (int i = 0; i < 510; i++)
    for (int j = 0; j < 27; j++)
      for (int k = 0; k < 27; k++) dp[i][j][k] = {INT_MAX, {26, 26}};
  printf("%d\n", r(0, 26, 26));
  int x1 = 26, x2 = 26;
  for (int i = 0; i < n; i++) {
    auto c = dp[i][x1][x2].second;
    for (int j = 0; j < m; j++) printf("%c", j & 1 ? c.second : c.first);
    printf("\n");
    x1 = c.first - 'a';
    x2 = c.second - 'a';
  }
}
