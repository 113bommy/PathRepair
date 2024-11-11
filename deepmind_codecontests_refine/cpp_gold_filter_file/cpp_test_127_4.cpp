#include <bits/stdc++.h>
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
using namespace std;
long long nextprime(long long x) {
  x++;
  long long n = x;
  long long c = 0, c1 = 0;
  while (true) {
    long long x1 = (long long)(sqrt(n));
    c1 = 0;
    for (long long i = 2; i < x1 + 1; i++) {
      if (n % i == 0) {
        c1++;
        break;
      }
    }
    if (c1 == 0) {
      break;
    } else
      n++;
  }
  return n;
}
long long binpow(long long a, long long b) {
  a %= M;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % M;
    a = a * a % M;
    b >>= 1;
  }
  return res;
}
void Solve() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  vector<char> cha(26);
  for (auto x : s) {
    cha[x - 'a']++;
  }
  if (t != "abc" || !cha[0] || !cha[1] || !cha[2]) {
    cout << s << endl;
    return;
  } else {
    while (cha[0]--) cout << 'a';
    while (cha[2]--) cout << 'c';
    while (cha[1]--) cout << 'b';
    for (long long i = 3; i < 26; i++)
      while (cha[i]--) {
        cout << char('a' + i);
      }
    cout << endl;
    return;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tcase;
  cin >> tcase;
  while (tcase--) {
    Solve();
  }
}
