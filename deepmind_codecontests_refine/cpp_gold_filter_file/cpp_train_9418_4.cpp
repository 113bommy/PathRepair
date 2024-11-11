#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  bool suc = false;
  int n = s.size();
  for (int i = 0; i < n; i++)
    if (!suc && s[i] % 2 == 0 && s[i] < s[n - 1])
      suc = true, swap(s[i], s[n - 1]);
  for (int i = n - 2; i >= 0; i--)
    if (!suc && s[i] % 2 == 0) suc = true, swap(s[i], s[n - 1]);
  if (suc)
    cout << s << '\n';
  else
    cout << "-1\n";
  return 0;
}
