#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 50;
const long long mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, i, j;
  cin >> n;
  string s;
  cin >> s;
  int f[10];
  for (i = 1; i < 10; ++i) cin >> f[i];
  for (i = 0; i < n; i++) {
    if (f[s[i] - '0'] > s[i] - '0') {
      j = i;
      while (f[s[j] - '0'] >= s[j] - '0') {
        s[j] = f[s[j] - '0'] + '0';
        ++j;
      }
      break;
    }
  }
  cout << s;
}
