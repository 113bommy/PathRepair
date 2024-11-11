#include <bits/stdc++.h>
using namespace std;
template <typename U, typename T>
void chmin(U &x, T y) {
  x = min(x, y);
}
template <typename U, typename T>
void chmax(U &x, T y) {
  x = max(x, y);
}
const int INF = INT_MAX / 3;
const double EPS = 1e-14;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int mod = 1000000007;
struct Mod {
  int num;
  Mod() : num(0) { ; }
  Mod(int n) : num((n % mod + mod) % mod) { ; }
  operator int() { return num; }
};
Mod operator+(Mod a, Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator-(Mod a, Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator*(Mod a, Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator+=(Mod &a, Mod b) { return a = a + b; }
Mod operator-=(Mod &a, Mod b) { return a = a - b; }
Mod operator*=(Mod &a, Mod b) { return a = a * b; }
Mod operator^(Mod a, int n) {
  if (n == 0) return Mod(1);
  Mod res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}
Mod inv(Mod a) { return a ^ (mod - 2); }
Mod operator/(Mod a, Mod b) { return a * inv(b); }
Mod fact[1024000], factinv[1024000];
void init() {
  fact[0] = Mod(1);
  factinv[0] = 1;
  for (int i = 0; i < (1024000 - 1); i++) {
    fact[i + 1] = fact[i] * Mod(i + 1);
    factinv[i + 1] = factinv[i] / Mod(i + 1);
  }
}
Mod comb(int a, int b) { return fact[a] * factinv[b] * factinv[a - b]; }
long long int pw(long long int a, long long int n) {
  if (n == 0) return 1;
  if (n % 2 == 1) return a * pow(a, n - 1);
  return pow(a * a, n / 2);
}
long long int n, k;
vector<long long int> a, b;
int main() {
  cout << fixed << setprecision(10);
  cin >> n >> k;
  long long int w = n / k;
  a.resize(w);
  b.resize(w);
  for (int i = 0; i < (w); i++) cin >> a[i];
  for (int i = 0; i < (w); i++) cin >> b[i];
  Mod ans = 1;
  for (int i = 0; i < (w); i++) {
    long long int s = (pw(10, k) - 1) / a[i] + 1 -
                      (pw(10, k - 1) * (b[i] + 1) - 1) / a[i] - 1 +
                      (b[i] > 0 ? (pw(10, k - 1) * (b[i]) - 1) / a[i] + 1 : 0);
    ans *= s;
  }
  cout << ans << endl;
  return 0;
}
