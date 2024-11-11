#include <bits/stdc++.h>
using namespace std;
const int N = 100005, P = 1000000007;
using ll = long long;
int n;
char s[N];
ll solve() {
  cin >> s;
  n = strlen(s);
  ll f = 0, s2 = 0, sum = 0, ak = 0, a1 = 0, kk = 1;
  for (int i = 0; i < n; i++) {
    f = (f * 100 + s2 * 100 + 220 * sum + 70 * (ak + P - a1) % P +
         56 * (kk - 1)) %
        P;
    s2 = (200 * s2 + 220 * sum + 65 * (kk - 1)) % P;
    sum = (sum * 20 + 11 * (kk - 1)) % P;
    if (s[i] != '4') {
      f = (f + (ak * 10 + 4) % P * ((ak * 10 + 7) % P)) % P;
      sum = (sum + (ak * 10 + 4) % P);
      s2 = (s2 + (ak * 10 + 4) % P * ((ak * 10 + 4) % P)) % P;
    }
    ak = (ak * 10 + s[i] - '0') % P;
    a1 = (a1 * 10 + 4) % P;
    kk = (kk - 1) * 2;
    kk += 1 + (s[i] == '7');
    kk %= P;
  }
  return f;
}
int main() {
  ios::sync_with_stdio(false);
  ll ans = P - solve();
  ans += solve();
  cout << ans % P << endl;
  return 0;
}
