#include <bits/stdc++.h>
using namespace std;
void print(long long a) { cout << a << '\t' << '\n'; }
void print(long long a, long long b) { cout << a << '\t' << b << '\t' << '\n'; }
void print(long long a, long long b, long long c) {
  cout << a << '\t' << b << '\t' << c << '\n';
}
void print(long long a, long long b, long long c, long long d) {
  cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}
void print(long long a, long long b, long long c, long long d, long long e) {
  cout << a << '\t' << b << '\t' << c << '\t' << d << '\t' << e << '\n';
}
void print(vector<long long> &a) {
  for (auto i : a) cout << i << " ";
  cout << '\n';
  ;
}
void print(string s) {
  cout << s;
  cout << '\n';
  ;
}
vector<long long> primes;
void seive() {
  long long n = 1e6;
  vector<long long> p(n + 1, 1);
  for (long long i = 2; i * i < n; i++)
    if (p[i])
      for (long long j = i * i; j <= n; j += i) p[j] = 0;
  for (long long i = 0; i <= n; i++)
    if (p[i]) primes.emplace_back(i);
}
void MAIN() {
  long long n, m, x, y;
  cin >> n >> m >> x >> y;
  long long ans = 0;
  y = min(2 * x, y);
  string s;
  while (n--) {
    cin >> s;
    for (long long i = 0; i < m; i++) {
      if (i and s[i] == '.' and s[i - 1] == '.')
        ans += y - x, i++;
      else if (s[i] == '.')
        ans += x;
    }
  }
  print(ans);
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long t;
  cin >> t;
  while (t--) MAIN();
  return 0;
}
