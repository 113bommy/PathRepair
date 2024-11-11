#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int mn = INT_MAX;
  string s;
  cin >> s;
  map<char, int> ct;
  for (int i = 0; i < s.size(); i++) ct[s[i]]++;
  mn = min(mn, ct['n'] / 3);
  mn = min(mn, ct['i']);
  mn = min(mn, ct['e'] / 3);
  mn = min(mn, ct['t']);
  cout << mn << endl;
}
