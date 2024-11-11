#include <bits/stdc++.h>
const long long int INF = 10000000000, MOD = 1e9 + 7, MAXN = 10000;
const long double EPS = 0.00000001;
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  int pref[1000000], suf[1000000];
  int a, b;
  cin >> a >> b;
  pref[0] = int(s[0] - '0') % a;
  for (int i = 1; i < s.size(); i++) {
    pref[i] = (pref[i - 1] * 10 + int(s[i] - '0')) % a;
  }
  int p = 10;
  suf[s.size() - 1] = int(s[s.size() - 1] - '0') % b;
  for (int i = s.size() - 2; i >= 0; i--) {
    suf[i] = (suf[i + 1] + int(s[i] - '0') * p) % b;
    p = (p * 10) % b;
  }
  for (int i = 1; i < s.size() - 1; i++) {
    if (pref[i] == 0 && suf[i + 1] == 0 && s[i + 1] != '0') {
      cout << "YES\n";
      cout << s.substr(0, i + 1) << "\n";
      cout << s.substr(i + 1, s.size() - 1) << "\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
