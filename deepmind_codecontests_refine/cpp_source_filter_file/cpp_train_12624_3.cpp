#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long int powe(long long int n, long long int m) {
  if (m == 0) return 1;
  long long int t = powe(n, m / 2);
  if (m % 2 == 0) return (t * t);
  return (((t * t)) * n);
}
long long int mpowe(long long int n, long long int m) {
  if (m == 0) return 1;
  long long int t = powe(n, m / 2);
  t %= 1000000000000000007;
  if (m % 2 == 0) return (t * t) % 1000000000000000007;
  return (((t * t) % 1000000000000000007) * n) % 1000000000000000007;
}
long long int logtwo(long long int n) {
  if (n == 1) return 0;
  return logtwo(n / 2) + 1;
}
long long int binpow(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int A[100005];
void solve() {
  int n, i;
  cin >> n;
  string s;
  cin >> s;
  int ans = 1;
  int b[n];
  int a, l = INT_MAX, li, lo, fans = INT_MIN;
  int v[n];
  int z = 0, o = 0;
  if (s[0] == '1')
    o++;
  else
    z++;
  for (i = 1; i < n; i++) {
    if (s[i] == '1') {
      if (z == 0)
        o++;
      else {
        z--;
        o++;
      }
    } else {
      if (o == 0)
        z++;
      else {
        o--;
        z++;
      }
    }
  }
  int total = o + z;
  int f = 0, st = total + 1;
  for (i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (f > 0) {
        v[i] = f;
        f--;
      } else {
        v[i] = st - 1;
        st--;
      }
    } else {
      if (st < total) {
        v[i] = st;
        st++;
      } else {
        v[i] = f + 1;
        f++;
      }
    }
  }
  cout << total << '\n';
  for (long long int i = 0; i < n; i++) cout << v[i] << " ";
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
