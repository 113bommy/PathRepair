#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int m;
long long cnt[1 << 18][100];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s >> m;
  n = s.size();
  cnt[0][0] = 1;
  for (int mask = 0; mask < 1 << n; mask++) {
    for (int mod = 0; mod < m; mod++) {
      for (int i = 0; i < n; i++) {
        if (mask & 1 << i) continue;
        if (!mask && s[i] == '0') continue;
        cnt[mask | 1 << i][(mod * 10 + s[i] - '0') % m] += cnt[mask][mod];
      }
    }
  }
  long long ans = cnt[(1 << n) - 1][0];
  map<char, int> k;
  for (char c : s) {
    k[c]++;
  }
  for (auto& it : k) {
    long long f = 1;
    for (int i = 2; i <= it.second; i++) {
      f *= i;
    }
    ans /= f;
  }
  cout << ans << endl;
  return 0;
}
