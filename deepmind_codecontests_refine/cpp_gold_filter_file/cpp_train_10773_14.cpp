#include <bits/stdc++.h>
using namespace std;
string s;
int a, b, n;
long long ans;
long long solve(int from, int to) {
  if (from == to) return s[from] - '0';
  for (int i = from; i <= to; i++)
    if (((a <= from && to <= b) || i < a || i > b) && s[i] == '+')
      return solve(from, i - 1) + solve(i + 1, to);
  for (int i = from; i <= to; i++)
    if (((a <= from && to <= b) || i < a || i > b) && s[i] == '*')
      return solve(from, i - 1) * solve(i + 1, to);
  return 0;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  if (0 & 1) freopen("input", "r", stdin);
  if (0 & 2) freopen("output", "w", stdout);
  cin >> s;
  n = int(s.size());
  for (a = 0; a < n; a += 2)
    if (a == 0 || s[a - 1] == '*')
      for (b = a; b < n; b += 2)
        if (b + 1 == n || s[b + 1] == '*') ans = max(ans, solve(0, n - 1));
  cout << ans << "\n";
  return 0;
}
