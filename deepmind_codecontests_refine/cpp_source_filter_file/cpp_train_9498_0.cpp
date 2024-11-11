#include <bits/stdc++.h>
using namespace std;
int rev_bin(int a) {
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    ans <<= 1;
    ans |= 1 & a;
    a >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  getline(cin, s);
  s = char(0) + s;
  int n = s.size();
  n++;
  int cur;
  int prev = 0;
  for (int i = 1; i < n; i++)
    cout << ((rev_bin(s[i - 1]) - rev_bin(s[i])) % 256 + 256) % 256 << '\n';
  return 0;
}
