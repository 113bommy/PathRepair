#include <bits/stdc++.h>
using namespace std;
long long p(long long a, long long b) { return a + rand() % (b - a + 1); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  long long n, k, pp, kk, ss, a;
  cin >> n >> k;
  pp = 1;
  kk = n;
  srand(3);
  while (1) {
    if (kk > n) kk = n;
    if (pp < 1) pp = 1;
    if (kk - pp + 1 <= k + k + k + k + 1) {
      a = p(pp, kk);
      cout << a << ' ' << a << '\n';
      cout.flush();
      cin >> s;
      if (s[0] == 'B') return 0;
      if (s[0] == 'Y') return 0;
      pp -= k;
      kk += k;
      continue;
    }
    ss = (pp + kk) / 2;
    cout << pp << ' ' << ss << '\n';
    cout.flush();
    cin >> s;
    if (s[0] == 'B') return 0;
    if (s[0] == 'Y') {
      pp -= k;
      kk = ss + k;
    } else {
      pp = ss - k;
      kk += k;
    }
  }
  return 0;
}
