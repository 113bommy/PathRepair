#include <bits/stdc++.h>
using namespace std;
string s;
int solve(int l, int r, char x) {
  int i;
  if (l == r) return s[l] != x;
  int cnt1 = 0;
  for (i = l; i <= (l + r) / 2; i++)
    if (s[i] != x) cnt1++;
  int u = solve((l + r) / 2 + 1, r, x + 1);
  int cnt2 = 0;
  for (i = (l + r) / 2 + 1; i <= r; i++)
    if (s[i] != x) cnt2++;
  int v = solve(l, (l + r) / 2, x + 1);
  return min(u + cnt1, v + cnt2);
}
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    cout << solve(0, n - 1, 'a') << endl;
  }
}
