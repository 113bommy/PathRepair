#include <bits/stdc++.h>
using namespace std;
long long int q, ans, sum;
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long int powe(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a);
    }
    a = (a * a);
    b /= 2;
  }
  return res;
}
long long int power(long long int a, long long int b, long long int M) {
  a %= M;
  long long int res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % M;
    }
    a = (a * a) % M;
    b /= 2;
  }
  return res;
}
long long int extendedEuclid(long long int A, long long int B, long long int &x,
                             long long int &y) {
  if (B == 0) {
    x = 1;
    y = 0;
    return A;
  } else {
    long long int x1, y1;
    long long int gcd = extendedEuclid(B, A % B, x1, y1);
    y = x1 - (A / B) * y1;
    x = y1;
    return gcd;
  }
}
long long int mi(long long int A, long long int M) {
  long long int x, y;
  extendedEuclid(A, M, x, y);
  if (x < 0) {
    x += (long long int)1000000007;
  }
  return x;
}
vector<bool> sieve(1000000, true);
void Sieve() {
  sieve[0] = false;
  sieve[1] = false;
  for (long long int i = 2; i * i <= 1000000; i++) {
    if (sieve[i] == true) {
      for (long long int j = i * i; j < 1000000; j += i) sieve[j] = false;
    }
  }
}
vector<long long int> sieve_spf;
void Sieve_spf() {
  const long long int n = 1e6 + 5;
  sieve_spf.resize(n);
  for (long long int i = 0; i < n; i++) sieve_spf[i] = i;
  sieve_spf[0] = -1;
  sieve_spf[1] = 1;
  for (long long int i = 2; i <= n; i += 2) sieve_spf[i] = 2;
  for (long long int i = 3; i <= n; i += 2)
    if (sieve_spf[i] == i)
      for (long long int j = i * i; j <= n; j += i)
        if (sieve_spf[j] == j) sieve_spf[j] = i;
}
bool comparator(const pair<long long int, long long int> &a,
                const pair<long long int, long long int> &b) {
  if (a.first > b.first)
    return true;
  else if (a.first == b.first && a.second < b.second)
    return true;
  else
    return false;
}
void the_happiest_place_on_earth() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
}
bool isUpcase(char c) {
  if (c >= 'A' && c <= 'Z')
    return true;
  else
    return false;
}
bool islowcase(char c) {
  if (c >= 'a' && c <= 'z')
    return true;
  else
    return false;
}
const int N = 200005;
long long int dp[15][1011][102];
vector<int> stuffing_avl, stuffing_req, dough_req, profit;
int n, m, c0, p0;
long long int totle_profit(int in, int dough_left, int stuffing, int prof) {
  if (in < 0) return (dough_left / c0) * p0;
  if (dp[in][dough_left][stuffing] != -1) return dp[in][dough_left][stuffing];
  if (dough_left >= dough_req[in] &&
      stuffing + stuffing_req[in] <= stuffing_avl[in]) {
    dp[in][dough_left][stuffing] =
        max(totle_profit(in - 1, dough_left, 0, prof),
            profit[in] + totle_profit(in, dough_left - dough_req[in],
                                      stuffing + stuffing_req[in],
                                      prof + profit[in]));
    return dp[in][dough_left][stuffing];
  }
  dp[in][dough_left][stuffing] = totle_profit(in - 1, dough_left, 0, prof);
  return dp[in][dough_left][stuffing];
}
void solve() {
  int a, b, c, d;
  cin >> n >> m >> c0 >> p0;
  memset(dp, -1, sizeof(dp));
  for (long long int i = 0; i < m; i++) {
    cin >> a >> b >> c >> d;
    stuffing_avl.push_back(a);
    stuffing_req.push_back(b);
    dough_req.push_back(c);
    profit.push_back(d);
  }
  cout << totle_profit(m - 1, n, 0, 0);
  return;
}
int main() {
  the_happiest_place_on_earth();
  q = 1;
  while (q--) {
    solve();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
