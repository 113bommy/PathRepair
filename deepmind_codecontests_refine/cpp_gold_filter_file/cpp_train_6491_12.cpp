#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int Max = 1e5 + 5;
const long long IFN = 1e18 + 5;
inline void norm(long long &a) {
  a %= mod;
  (a < 0) && (a += mod);
}
inline long long modAdd(long long a, long long b) {
  a %= mod, b %= mod;
  norm(a), norm(b);
  return (a + b) % mod;
}
inline long long modSub(long long a, long long b) {
  a %= mod, b %= mod;
  norm(a), norm(b);
  return (a - b) % mod;
}
inline long long modMul(long long a, long long b) {
  a %= mod, b %= mod;
  norm(a), norm(b);
  return (a * b) % mod;
}
long long bigmod(long long a, long long p, long long M) {
  p %= (M - 1);
  long long result = 1LL;
  while (p > 0LL) {
    if (p & 1LL) result = result * a % M;
    a = a * a % M;
    p >>= 1LL;
  }
  return result;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long inverse(long long a, long long M) {
  if (gcd(a, M) == 1) return bigmod(a, M - 2, M) % M;
  return 1;
}
long long ncr(long long a, long long b) {
  long long x = max(a - b, b), ans = 1;
  for (long long K = a, L = 1; K >= x + 1; K--, L++) {
    ans = ans * K % mod;
    ans = ans * inverse(L, mod) % mod;
  }
  return ans;
}
void F_I_O() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  int t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string c = "0123456789";
    long long r = n;
    long long ans = n;
    while (1) {
      string s = to_string(r);
      bool ok = false;
      int i = s.size() - 1;
      for (; i >= 0; i--) {
        if (s[i] != '9') {
          s[i] = '9';
          ok = true;
          break;
        }
      }
      if (ok) {
        i--;
        for (; i >= 0; i--) {
          if (s[i] == '0') {
            s[i] = '9';
          } else {
            for (int j = 0; j < 10; j++) {
              if (c[j] == s[i]) {
                s[i] = c[j - 1];
                break;
              }
            }
            break;
          }
        }
      }
      i = 0;
      string e = "";
      while (s[i] == '0') {
        i++;
      }
      for (; i < s.size(); i++) {
        e += s[i];
      }
      long long val = stoll(e);
      long long g = n - val;
      r = stoll(e);
      if (g <= m && g >= 0) {
        ans = val;
      } else {
        break;
      }
      ok = true;
      for (int i = 0; i < e.size(); i++) {
        if (e[i] != '9') {
          ok = false;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    cout << ans << '\n';
  }
}
