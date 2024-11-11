#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323846264338;
const long long INF = 1000000000000000000;
const long long INF1 = 1000000000;
const long long MOD = 1000000007;
long long mpow(long long a, long long b) {
  a %= MOD;
  if (!b) return 1;
  long long temp = mpow(a, b / 2);
  temp = (temp * temp) % MOD;
  if (b % 2) return (a * temp) % MOD;
  return temp;
}
long long _pow(long long a, long long b) {
  if (!b) return 1;
  long long temp = _pow(a, b / 2);
  temp = (temp * temp);
  if (b % 2) return (a * temp);
  return temp;
}
long long mod_in(long long n) { return mpow(n, MOD - 2); }
long long cl(long long a, long long b) {
  if (a % b) return 1 + a / b;
  return a / b;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    long long n = s.length();
    long long cr = 0, cs = 0, cp = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R')
        cr++;
      else if (s[i] == 'S')
        cs++;
      else if (s[i] == 'P')
        cp++;
    }
    if (cr != 0 && cs == 0 && cp == 0) {
      for (int i = 0; i < n; i++) s[i] = 'P';
      cout << s << "\n";
      continue;
    }
    if (cs != 0 && cr == 0 && cp == 0) {
      for (int i = 0; i < n; i++) s[i] = 'R';
      cout << s << "\n";
      continue;
    }
    if (cp != 0 && cs == 0 && cr == 0) {
      for (int i = 0; i < n; i++) s[i] = 'S';
      cout << s << "\n";
      continue;
    }
    if (cr >= cs && cr >= cp) {
      for (int i = 0; i < n; i++) s[i] = 'P';
      cout << s << "\n";
      continue;
    } else if (cs >= cr && cs >= cp) {
      for (int i = 0; i < n; i++) s[i] = 'R';
      cout << s << "\n";
      continue;
    } else if (cp >= cr && cp >= cs) {
      for (int i = 0; i < n; i++) s[i] = 'S';
      cout << s << "\n";
      continue;
    }
  }
  return 0;
}
