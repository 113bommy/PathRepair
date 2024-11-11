#include <bits/stdc++.h>
using namespace std;
long long int p4[] = {-1, 1, 0, 0};
long long int q4[] = {0, 0, 1, -1};
long long int p8[] = {-1, 1, 0, 0, -1, 1, -1, 1};
long long int q8[] = {0, 0, 1, -1, 1, 1, -1, -1};
long long int gcd(long long int a, long long int b) {
  if (b > a) gcd(b, a);
  return ((b == 0) ? a : gcd(b, a % b));
}
long long int lcm(long long int a, long long int b) {
  long long int p = (a * b) / (gcd(a, b));
  return p;
}
long long int BigMod(long long int a, long long int b, long long int m) {
  if (!b) return 1;
  long long int ans = BigMod(a, b / 2, m);
  ans = (ans * ans) % m;
  if (b & 1) ans = (ans * a) % m;
  return ans;
}
long long int Mod_inv(long long int a, long long int m) {
  return BigMod(a, m - 2, m);
}
long long int sum(long long int a, long long int b, long long int m) {
  return a >= m - b ? a - (m - b) : a + b;
}
long long int multiply(long long int a, long long int b, long long int m) {
  long long int ans = 0;
  if (b > a) swap(a, b);
  while (b) {
    if (b & 1) ans = sum(ans, a, m);
    b >>= 1;
    a = sum(a, a, m);
  }
  return ans;
}
long long int a[2000005], b[2000005];
map<long long int, long long int> mp;
string s, s1, s2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j, k;
  long long int l, m, n, c, d, p, q, r;
  long long int cs = 0, tc, t = 1, flg, f, sm;
  while (cin >> n) {
    long long int id = 0;
    sm = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      p = a[i];
      if (mp.count(p - 1))
        mp[p] = mp[p - 1] + 1;
      else
        mp[p] = 1;
      if (mp[p] > sm) {
        sm = mp[p];
        id = i;
      }
    }
    cout << sm << endl;
    p = a[id] - sm + 1;
    for (i = 1; i <= n; i++) {
      if (p == a[i]) {
        cout << i << " ";
        p++;
      }
    }
    cout << endl;
  }
  return 0;
}
