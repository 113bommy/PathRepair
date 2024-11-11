#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long N = pow(10, 9) + 7;
void ipgraph(long long n, long long m);
long long power(long long a, long long b, long long p);
long long modp(long long n, long long m);
long long moda(long long n, long long m);
long long mods(long long n, long long m);
vector<vector<char>> v;
vector<bool> vis;
void solve() {
  long long a[6];
  for (long long i = 0; i < 6; i++) cin >> a[i];
  long long base, s1, s2, ans = 0, n, fir, d;
  base = a[3], s1 = a[4], s2 = a[2];
  n = min(s1, s2);
  fir = 2 * base + 1;
  d = 2;
  ans += n * (2 * fir + (n - 1) * d) / 2;
  base = a[0], s1 = a[1], s2 = a[5];
  n = min(s1, s2);
  fir = 2 * base + 1;
  d = 2;
  ans += n * (2 * fir + (n - 1) * d) / 2;
  ans += (a[4] + a[2] - 2 * min(a[4], a[2])) * (fir + (n - 1) * d);
  cout << (ans) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
  cerr << endl
       << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
void ipgraph(long long n, long long m) {
  v.assign(n, {});
  vis.assign(n, 0);
  long long x, y;
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    x--, y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
}
long long power(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long c = power(a, b / 2, p);
  if (b % 2 == 0)
    return ((c * c) % p);
  else
    return ((((c * c) % p) * a) % p);
}
long long modp(long long n, long long m) { return ((n % N * m % N) + N) % N; }
long long moda(long long n, long long m) { return ((n % N + m % N) + N) % N; }
long long mods(long long n, long long m) { return ((n % N - m % N) + N) % N; }
