#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using mii = map<int, int>;
const double Eps = 1e-8;
const int Inf = 1e9 + 9;
const int Mod = 1e9 + 7;
const int N = 1e5 + 9;
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = {-1, 0, 1, 0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
constexpr double pi = 3.141592653589793238462643383279502884L;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
void prime_siever(long long p) {
  bool prime[p + 9];
  for (long long i = 2; i * i <= p; i++)
    if (prime[i] == 0)
      for (long long j = i * i; j <= p; j += i) prime[j] = 1;
}
int mul(int a, int b) { return (1LL * a * b) % Mod; }
int add(int a, int b) {
  a += b;
  if (a >= Mod) a -= Mod;
  if (a < 0) a += Mod;
  return a;
}
long long bin_power(long long a, long long n) {
  if (a == 0) return 0;
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % Mod;
      n--;
    } else {
      a = (a * a) % Mod;
      n /= 2;
    }
  }
  return res;
}
int countbi1(int x) {
  int cnt = 0;
  while (x > 0) {
    if (x & 1) cnt++;
    x /= 2;
  }
  return cnt;
}
int n, k, a[N], A, c[N];
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= k;
  }
  cin >> A;
  for (int i = 0; i < n; i++) cin >> c[i];
  priority_queue<int, vector<int>, greater<int>> qi;
  long long cur = 0, cost = 0;
  for (int i = 0; i < n; i++) {
    qi.push(c[i]);
    if (cur >= a[i]) continue;
    while (cur < a[i]) {
      if (qi.empty()) {
        cout << -1 << '\n';
        return;
      }
      cur += A;
      cost += qi.top();
      qi.pop();
    }
  }
  cout << cost << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
