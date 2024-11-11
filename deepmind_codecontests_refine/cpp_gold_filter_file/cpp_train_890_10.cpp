#include <bits/stdc++.h>
using namespace std;
long long n;
long long i = 0, j = 0, k = 0;
long long a = 0, b = 0, c = 0;
char ch;
string s;
string rr = "RR";
string gg = "GG";
string bb = "BB";
vector<long long> v;
deque<long long> d;
set<long long> se;
long long row[1000002];
long long col[1000002];
long long date[1000002];
long long sum = 0;
long long pro = 1;
long long ans = 0;
long long t;
map<long long, long long> m;
char str[6000];
long long C(long long n, long long m) {
  if (m < n - m) m = n - m;
  long long ans = 1;
  for (long long i = m + 1; i <= n; i++) ans *= i;
  for (long long i = 1; i <= n - m; i++) ans /= i;
  return ans;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool is_prime(long long x) {
  long long n = floor(sqrt(x) + 0.01);
  for (long long i = (2); i < (n + 1); ++i) {
    if (x % i == 0) return 0;
  }
  return 1;
}
long long solve() {
  k = c / a;
  j = c / b;
  for (long long i = (1); i < (k + 1); ++i) {
    se.insert(i * a);
  }
  for (long long i = (1); i < (j + 1); ++i) {
    se.insert(i * b);
  }
  return (j + k - se.size());
}
void run() {
  cin >> a;
  cin >> b;
  cin >> c;
  cout << solve();
}
signed main() {
  std::ios::sync_with_stdio(false);
  run();
}
