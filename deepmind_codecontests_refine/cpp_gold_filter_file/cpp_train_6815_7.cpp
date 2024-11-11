#include <bits/stdc++.h>
using namespace std;
inline int64_t max(int64_t a, int64_t b) { return (a > b) ? a : b; }
inline int64_t min(int64_t a, int64_t b) { return (a < b) ? a : b; }
inline int64_t max3(int64_t a, int64_t b, int64_t c) {
  return max(a, max(b, c));
}
inline int64_t min3(int64_t a, int64_t b, int64_t c) {
  return min(a, min(b, c));
}
int64_t gcd(int64_t a, int64_t b) { return (a % b == 0) ? b : gcd(b, a % b); }
int64_t pow3(int64_t a, int64_t b, int64_t m = 1000000007) {
  int64_t res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q = 1;
  while (q--) {
    string s;
    cin >> s;
    int64_t n = s.size();
    int64_t l, r;
    cin >> l >> r;
    int64_t m = 1e9 + 7;
    int64_t rp[n], rs[n];
    rp[0] = (s[0] - 48) % l;
    for (int64_t i = 1; i < n; i++) rp[i] = (rp[i - 1] * 10 + s[i] - 48) % l;
    rs[n - 1] = (s[n - 1] - 48) % r;
    int64_t temp = 10;
    for (int64_t i = n - 2; i > -1; i--) {
      rs[i] = (temp * (s[i] - 48) + rs[i + 1]) % r;
      temp = (temp * 10) % r;
    }
    int64_t p = 1;
    for (; p < n; p++)
      if (rp[p - 1] == 0 && rs[p] == 0 && s[p] != '0') break;
    if (p == n)
      cout << "NO";
    else {
      cout << "YES" << endl;
      for (int64_t i = 0; i < p; i++) cout << s[i];
      cout << endl;
      for (int64_t i = p; i < n; i++) cout << s[i];
    }
  }
  return 0;
}
