#include <bits/stdc++.h>
using namespace std;
int const MOD = 1e9 + 7;
int n, cnt, mx;
long long ans = 1;
bool mark[26];
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    mark[s[i] - 'A']++;
  }
  for (int i = 0; i < 26; i++) {
    if (mark[i] > mx) {
      cnt = 0;
      mx = mark[i];
    }
    if (mark[i] == mx) cnt++;
  }
  for (int i = 0; i < n; i++) {
    (ans *= cnt) %= MOD;
  }
  return cout << ans, 0;
}
