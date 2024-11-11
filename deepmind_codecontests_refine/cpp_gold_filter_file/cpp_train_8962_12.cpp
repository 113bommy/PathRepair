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
long long int a[1000005], b[1000005], as[1000005];
pair<long long int, long long int> pr[1000005], pr2[1000005];
string s, s1, s2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j, k;
  long long int l, m, n, c, d, p, q, r;
  long long int cs = 0, tc, t = 1, flg, f, sm;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p >> q;
    pr2[i] = {p, q};
    pr[i] = {q - p, i};
  }
  sort(pr + 1, pr + 1 + n, greater<pair<long long int, long long int> >());
  for (i = 1; i <= n; i++) {
    p = pr[i].second;
    a[i] = a[i - 1] + pr2[p].first;
    b[i] = b[i - 1] + pr2[p].second;
  }
  for (i = 1; i <= n; i++) {
    p = pr[i].second;
    as[p] = (b[n] - b[i]) + (pr2[p].first * (n - i));
    as[p] += a[i - 1] + (pr2[p].second * (i - 1));
  }
  for (i = 1; i <= m; i++) {
    cin >> p >> q;
    c = pr2[p].first + pr2[q].second;
    d = pr2[p].second + pr2[q].first;
    f = min(c, d);
    as[p] -= f;
    as[q] -= f;
  }
  for (i = 1; i <= n; i++) cout << as[i] << " ";
  cout << endl;
  return 0;
}
