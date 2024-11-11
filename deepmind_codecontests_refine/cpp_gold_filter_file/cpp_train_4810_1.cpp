#include <bits/stdc++.h>
using namespace std;
int inf = 1000000005;
long long int llinf = 2000000000000000005LL;
long long int mod = 1000000007;
long long int mod9 = 1000000009;
double pi = 3.1415926535897;
double eps = 1e-15;
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1}, dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
vector<bool> isprime;
vector<int> primes;
void seive(int n, bool wantlist = true) {
  isprime.resize(n + 1, true);
  isprime[0] = isprime[1] = false;
  int sq = sqrt(n + 1);
  for (int i = 2; i < sq + 1; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= n; j += i) isprime[j] = false;
    }
  }
  for (int i = 2; wantlist && i <= n; i++) {
    if (isprime[i]) primes.push_back(i);
  }
}
template <class T>
inline T gcd(T a, T b) {
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <class T>
inline T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
template <class T>
inline vector<T> operator+(vector<T>& a, vector<T>& b) {
  assert(a.size() == b.size());
  int n = a.size();
  vector<T> c(n);
  for (int i = 0; i < n; i++) c[i] = a[i] + b[i];
  return c;
}
int fastMax(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y; }
inline long long int bexp(long long int x, long long int n,
                          long long int m = mod) {
  long long int res = 1;
  x %= m;
  while (n) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
inline bool ispalin(string& str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++)
    if (str[i] != str[n - i - 1]) return false;
  return true;
}
int len;
long long int mem[205][205], k;
long long int ways(string& s, int pos, int op) {
  if (pos == len) return op == 0;
  if (mem[pos][op] != -1) return mem[pos][op];
  long long int res = 0;
  if (s[pos] != ')') res += ways(s, pos + 1, op + 1);
  if (s[pos] != '(' && op) res += ways(s, pos + 1, op - 1);
  return mem[pos][op] = min(res, k);
}
int main() {
  int n, m;
  cin >> n >> m >> k;
  len = n + m - 1;
  vector<pair<int, int> > a(n + m - 1, {inf, -1});
  for (int i = 0; i < n + m - 1; i++) a[i].second = i;
  string s(n + m - 1, '?');
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      ;
      a[i + j].first = min(a[i + j].first, x);
    }
  sort(a.begin(), a.end());
  for (int i = 0; i < m + n - 1; i++) {
    int pos = a[i].second;
    s[pos] = '(';
    memset(mem, -1, sizeof(mem));
    if (ways(s, 0, 0) < k) {
      k -= ways(s, 0, 0);
      s[pos] = ')';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << s[i + j];
    printf("\n");
    ;
  }
}
