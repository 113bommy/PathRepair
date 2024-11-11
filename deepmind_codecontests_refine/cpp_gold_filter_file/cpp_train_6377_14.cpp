#include <bits/stdc++.h>
using namespace std;
bool isVowel(char ch) {
  string z = "aeiouAEIOU";
  return z.find(ch) != -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  vector<int> pf(s.size() + 1), sf(s.size() + 2, -666666666);
  for (int i = 1; i <= s.size(); i++)
    pf[i] = pf[i - 1] + (isVowel(s[i - 1]) ? -1 : 2);
  for (int i = s.size(); i >= 0; i--) sf[i] = max(sf[i + 1], pf[i]);
  map<int, int> mp;
  int mx = 0;
  int n = s.size();
  for (int i = 0; i <= n; i++)
    if (sf[i] >= pf[i]) {
      int l = i, r = n;
      while (l < r) {
        int m = (l + r + 1) / 2;
        if (sf[m] >= pf[i])
          l = m;
        else
          r = m - 1;
      }
      if (r - i == 0) continue;
      mp[r - i]++;
      mx = max(mx, r - i);
    }
  if (mp.empty()) return cout << "No solution\n", 0;
  cout << mx << " " << mp[mx] << "\n";
}
