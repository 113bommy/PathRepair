#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
void solve() {
  string s;
  cin >> s;
  set<char> occur(s.begin(), s.end());
  int n = occur.size();
  if (n & 1)
    cout << "IGNORE HIM!\n";
  else
    cout << "CHAT WITH HER!\n";
}
