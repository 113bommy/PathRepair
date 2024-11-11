#include <bits/stdc++.h>
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int exp(long long int x, long long int y, long long int mod) {
  long long int res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long int modinverse(long long int x, long long int mod) {
  return exp(x, mod - 2, mod);
}
using namespace std;
const long long int inf = 0x3f3f3f3f3f3f3f3fll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n;
  cin >> n;
  string s[n];
  vector<pair<long long int, long long int> > ansr, ansc;
  for (long long int i = 0; i < n; i++) cin >> s[i];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      if (s[i][j] == '.') {
        ansr.push_back(make_pair(i, j));
        break;
      }
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      if (s[j][i] == '.') {
        ansc.push_back(make_pair(j, i));
        break;
      }
    }
  }
  if (ansr.size() == n) {
    for (long long int i = 0; i < n; i++)
      cout << ansr[i].first + 1 << " " << ansr[i].second + 1 << '\n';
  } else if (ansc.size() == n) {
    for (long long int i = 0; i < n; i++)
      cout << ansc[i].first + 1 << " " << ansc[i].second + 1 << '\n';
  } else
    cout << -1;
  return 0;
}
