#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MOD2 = 998244353;
vector<int> bases;
const long long int LLINF = 1ll << 60;
const char en = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {
  cout << "YES" << en;
  exit(0);
}
void no() {
  cout << "NO" << en;
  exit(0);
}
inline int rund() {
  int x576363482791fuweh = rng();
  return abs(x576363482791fuweh) % RAND_MAX;
}
template <class T>
void prVec(vector<T> w) {
  cout << w.size() << endl;
  for (int i = 0; i < int(w.size()) - 1; ++i) cout << w[i] << ' ';
  if (w.size()) cout << w[w.size() - 1] << endl;
}
long long int raand() {
  long long int a = rund();
  a *= RAND_MAX;
  a += rund();
  return a;
}
long long int raaand() { return raand() * (MOD - 7) + raand(); }
string to_upper(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A';
  return a;
}
string to_lower(string a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
  return a;
}
long long int sti(string a) {
  long long int k = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    k *= 10;
    k += a[i] - '0';
  }
  return k;
}
string its(long long int k) {
  if (k == 0) return "0";
  string a;
  while (k) {
    a.push_back((k % 10) + '0');
    k /= 10;
  }
  reverse(a.begin(), a.end());
  return a;
}
long long int min(long long int a, int b) {
  if (a < b) return a;
  return b;
}
long long int min(int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int max(long long int a, int b) {
  if (a > b) return a;
  return b;
}
long long int max(int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
template <class T, class K>
pair<T, K> mp(T a, K b) {
  return make_pair(a, b);
}
inline int mult(long long int a, long long int b) { return (a * b) % MOD; }
inline int pot(int n, int k) {
  if (k == 0) return 1;
  long long int a = pot(n, k / 2);
  a = mult(a, a);
  if (k % 2)
    return mult(a, n);
  else
    return a;
}
int divide(int a, int b) { return mult(a, pot(b, MOD - 2)); }
int sub(int a, int b) { return (a - b + MOD) % MOD; }
int add(int a, int b) { return (a + b) % MOD; }
bool prime(long long int a) {
  if (a == 1) return 0;
  for (int i = 2; i <= round(sqrt(a)); ++i) {
    if (a % i == 0) return 0;
  }
  return 1;
}
long long int has(string first) {
  long long int h1 = 0, h2 = 0;
  first = to_lower(first);
  for (char a : first) {
    h1 *= bases[0];
    h1 += a - 'a';
    h1 %= bases[3];
    h2 *= bases[1];
    h2 += a - 'a';
    h2 %= bases[4];
  }
  return h1 * (MOD + 13893829) + h2;
}
const int N = 300010;
int n, k;
double dp[51][N];
double pr2[N], pr3[N];
long long int pr[N];
double h[N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
inline double cost(int i, int j) {
  return pr2[j + 1] - pr2[i] - (pr3[j + 1] - pr3[i]) * (pr[i]);
}
void comp(int l, int r, int oL, int oR, int k) {
  if (l > r) return;
  double op1 = LLINF;
  int op2 = 0;
  int mid = (l + r) / 2;
  for (int i = oL; i <= min(mid, oR); ++i) {
    if (dp[k - 1][i] + cost(i, mid) < op1) {
      op1 = dp[k - 1][i] + cost(i, mid);
      op2 = i;
    }
  }
  dp[k][mid + 1] = op1;
  comp(l, mid - 1, oL, op2, k);
  comp(mid + 1, r, op2, oR, k);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 10; ++i)
    bases.push_back((raand() % MOD + 13893829) % MOD);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    pr[i + 1] = pr[i] + h[i];
    pr2[i + 1] = pr[i + 1] / h[i] + pr2[i];
    pr3[i + 1] = 1 / h[i] + pr3[i];
  }
  for (int i = 1; i <= n; ++i) dp[0][i] = LLINF;
  for (int i = 1; i <= k; ++i) {
    comp(0, n - 1, 0, n - 1, i);
  }
  cout << fixed << setprecision(10) << dp[k][n];
}
