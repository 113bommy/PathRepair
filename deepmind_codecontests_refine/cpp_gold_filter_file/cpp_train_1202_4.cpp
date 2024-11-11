#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  long long u = 0, d = 0, r = 0, l = 0;
  cin >> s;
  if (s.length() % 2 == 1) {
    cout << "-1";
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'U') u++;
    if (s[i] == 'R') r++;
    if (s[i] == 'D') d++;
    if (s[i] == 'L') l++;
  }
  cout << (abs(l - r) + abs(d - u)) / 2;
  return 0;
}
