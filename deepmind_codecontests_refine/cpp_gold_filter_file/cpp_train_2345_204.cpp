#include <bits/stdc++.h>
using namespace std;
const long long int LL_MAX = 1e18 + 5;
const int MX = INT_MAX;
const long long int mod = 1000000007;
const int maxx = 2e5;
typedef unordered_map<int, int> umapII;
typedef const char* cstr;
int strToInt(string& a) {
  stringstream x(a);
  int b;
  x >> b;
  return b;
}
void readI(int& a) { cin >> a; }
void readI(int& a, int& b) { cin >> a >> b; }
void readI(int& a, int& b, int& c) { cin >> a >> b >> c; }
vector<int> readVI(int n) {
  vector<int> a(n);
  for (int i = 0; i < (int)n; i++) cin >> a[i];
  return a;
}
vector<vector<int> > readVVI(int n, int m) {
  vector<vector<int> > a(n, vector<int>(m));
  for (int i = 0; i < (int)n; i++) a[i] = readVI(m);
  return a;
}
vector<long long int> readVLL(long long int n) {
  vector<long long int> a(n);
  for (int i = 0; i < (int)n; i++) cin >> a[i];
  return a;
}
vector<vector<long long int> > readVVLL(long long int n, long long int m) {
  vector<vector<long long int> > a(n, vector<long long int>(m));
  for (int i = 0; i < (int)n; i++) a[i] = readVLL(m);
  return a;
}
const int d4i[4] = {-1, 0, 1, 0};
const int d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool rev(int a, int b) { return a >= b; }
long long int fac[1000001];
void factorial() {
  long long int MOD = 1e9 + 7;
  fac[0] = 1;
  for (long long int i = 1; i < 1000001; i++)
    fac[i] = (fac[i - 1] % MOD * (i % MOD)) % MOD;
}
long long int power(long long int a, long long int b,
                    long long int m = (1000 * 1000 * 1000 + 7)) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % (1000 * 1000 * 1000 + 7);
    a = (a * a) % (1000 * 1000 * 1000 + 7);
    b >>= 1;
  }
  return res;
}
long long int inverse(long long int a,
                      long long int m = (1000 * 1000 * 1000 + 7)) {
  return power(a, m - 2, m);
}
vector<bool> soe(int n) {
  vector<bool> is_prime(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return is_prime;
}
string yes = "YES\n", no = "NO\n";
void file() {}
void solve() {
  long long int a;
  cin >> a;
  long long int k = 2520;
  cout << (a) / k << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(25);
  solve();
  return 0;
}
