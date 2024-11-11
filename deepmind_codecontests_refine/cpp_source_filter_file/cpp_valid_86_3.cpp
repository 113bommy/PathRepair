#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long fac[1000000];
void solve(long long testcase) {
  long long n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long ans = 0;
  long long i = 0;
  while (i < n) {
    string sor = "", tor = "";
    sor += s[i];
    tor += t[i];
    long long x = stoi(sor), y = stoi(tor);
    if (x ^ y) {
      ans += 2;
      i++;
    } else {
      if (s[i] == '1') {
        if (i == n - 1) {
          i++;
          continue;
        } else {
          if (s[i + 1] == '0' || t[i + 1] == '0') {
            ans += 2;
            i += 2;
          } else {
            i++;
            continue;
          }
        }
      } else {
        if (i == n - 1) {
          ans += 1;
          i++;
          continue;
        } else {
          if (s[i + 1] == '1' || t[i + 1] == '1') {
            ans += 2;
            i += 2;
          } else {
            ans += 1;
            i++;
            continue;
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return;
}
signed main() {
  long long test = 1;
  cin >> test;
  for (long long init = 1; init <= test; init++) {
    solve(init);
  }
  return 0;
}
