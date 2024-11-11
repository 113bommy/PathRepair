#include <bits/stdc++.h>
using namespace std;
void file() { freopen("divisors.in", "r", stdin); }
const int maxsize = 1e9 + 5, oo = 0X3f3f3f3f;
int n, m, q, tot, a, t, b, ans;
bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}
int freq[30];
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    tot = 0;
    cin >> a;
    m = 1 + floor(log10(a));
    if (m < q) {
      ans++;
    } else {
      t = a;
      while (a) {
        b = a % 10;
        if (b == 4 || b == 7) tot++;
        a /= 10;
      }
      if (tot == q) ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
