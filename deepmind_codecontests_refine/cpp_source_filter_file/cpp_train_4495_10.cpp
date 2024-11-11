#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  set<char> st = {'a', 'e', 'i', 'o', 'u'};
  for (auto x : s) {
    char h = tolower(x);
    if (st.count(h))
      continue;
    else
      cout << "." << h;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  };
  return 0;
}
