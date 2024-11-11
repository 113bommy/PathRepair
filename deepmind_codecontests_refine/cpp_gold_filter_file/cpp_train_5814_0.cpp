#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t; cin >> s >> t; reverse(s.begin(), s.end());
  cout << ((t == s) ? "YES" : "NO") << endl;
}