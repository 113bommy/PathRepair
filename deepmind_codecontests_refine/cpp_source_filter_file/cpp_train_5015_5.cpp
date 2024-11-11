#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
bool isPrime(long long a) {
  long long i;
  for (i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return (a != 1);
}
bool isPalindrom(const string &s, int l, int r) {
  for (int i = 0; i < (r - l + 1) / 2; i++) {
    if (s[l + i] != s[r - i]) {
      return 0;
    }
  }
  return 1;
}
template <class type1>
type1 gcd(type1 a, type1 b) {
  type1 t;
  while (b) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
long long positiveMod(long long v, long long md) {
  v = v % md;
  if (v < 0) {
    v += md;
  }
  return v;
}
void solve() {
  string s;
  int n, k, i, j, a, b, c, res = (1000000007ll), tr, r1, r2, r3, g1, g2, g3, b1,
                           b2, b3;
  r1 = r2 = r3 = g1 = g2 = g3 = b1 = b2 = b3 = 0;
  cin >> n >> k;
  cin >> s;
  s = "#" + s;
  for (i = 1; i <= k; i++) {
    if (i % 3 == 1) {
      if (s[i] == 'R') {
        r1++;
      } else if (s[i] == 'G') {
        g1++;
      } else {
        b1++;
      }
    } else if (i % 3 == 2) {
      if (s[i] == 'R') {
        r2++;
      } else if (s[i] == 'G') {
        g2++;
      } else {
        b2++;
      }
    } else {
      if (s[i] == 'R') {
        r3++;
      } else if (s[i] == 'G') {
        g3++;
      } else {
        b3++;
      }
    }
  }
  res = k - max(r1 + g2 + b3, min(r2 + g3 + b1, r3 + g1 + b2));
  for (i = k + 1; i <= n; i++) {
    if (i % 3 == 1) {
      if (s[i] == 'R') {
        r1++;
      } else if (s[i] == 'G') {
        g1++;
      } else {
        b1++;
      }
    } else if (i % 3 == 2) {
      if (s[i] == 'R') {
        r2++;
      } else if (s[i] == 'G') {
        g2++;
      } else {
        b2++;
      }
    } else {
      if (s[i] == 'R') {
        r3++;
      } else if (s[i] == 'G') {
        g3++;
      } else {
        b3++;
      }
    }
    i -= k;
    if (i % 3 == 1) {
      if (s[i] == 'R') {
        r1--;
      } else if (s[i] == 'G') {
        g1--;
      } else {
        b1--;
      }
    } else if (i % 3 == 2) {
      if (s[i] == 'R') {
        r2--;
      } else if (s[i] == 'G') {
        g2--;
      } else {
        b2--;
      }
    } else {
      if (s[i] == 'R') {
        r3--;
      } else if (s[i] == 'G') {
        g3--;
      } else {
        b3--;
      }
    }
    i += k;
    res = min(res, k - max(r1 + g2 + b3, max(r2 + g3 + b1, r3 + g1 + b2)));
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, i, a, b, c;
  cin >> n;
  for (i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
