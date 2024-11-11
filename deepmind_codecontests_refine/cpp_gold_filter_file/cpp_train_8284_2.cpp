#include <bits/stdc++.h>
using namespace std;
long long n, i, cnt(0), res(0), l, t(0);
const long long mod = 1e9 + 7;
string s;
void Init() {
  cin >> s;
  l = s.length();
  for (i = 0; i < l; i++) {
    if (s[i] == 'a')
      t = ((t + 1) * 2 - 1) % mod;
    else
      res = (res + t) % mod;
  }
  cout << res;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  Init();
}
