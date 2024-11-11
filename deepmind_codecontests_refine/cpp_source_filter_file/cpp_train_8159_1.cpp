#include <bits/stdc++.h>
using namespace std;
long long ans = 1;
void Mul(int x) { ans *= x; }
bool Let(char c) { return c >= 'A' && c <= 'Z'; }
int f[160];
int main() {
  f[0] = 1;
  for (int i = 1; i < 50; ++i) f[i] = f[i - 1] * i;
  string s;
  cin >> s;
  map<char, int> mp;
  int c10 = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == '?') c10++;
    if (Let(s[i])) mp[s[i]]++;
  }
  int n = 10;
  int k = (int)mp.size();
  if (s[0] == '?') {
    c10--;
    Mul(9);
  } else if (Let(s[0])) {
    Mul(9);
    n--;
    k--;
  }
  ans *= f[n] / f[n - k] / f[k];
  cout << ans;
  while (c10-- > 0) cout << "0";
  cout << endl;
  return 0;
}
