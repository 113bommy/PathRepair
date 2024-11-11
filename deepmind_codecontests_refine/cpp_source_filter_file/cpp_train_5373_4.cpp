#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  if (s.size() < k) {
    cout << "impossible";
    return;
  }
  set<char> x;
  for (int i = 0; i < s.size(); i++) {
    x.insert(s[i]);
  }
  if (k - x.size() > 0)
    cout << k - x.size();
  else {
    cout << "0";
  }
  return;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
