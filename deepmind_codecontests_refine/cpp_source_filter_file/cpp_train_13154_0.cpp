#include <bits/stdc++.h>
using namespace std;
void tool();
void solve() {
  string name;
  cin >> name;
  int fre[26] = {0}, dist;
  for (char ch : name) {
    fre[ch - 'a']++;
    if (fre[ch - 'a'] == 1) dist++;
  }
  if (dist & 1)
    cout << "IGNORE HIM!";
  else
    cout << "CHAT WITH HER!";
}
int32_t main() {
  tool();
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
void tool() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
