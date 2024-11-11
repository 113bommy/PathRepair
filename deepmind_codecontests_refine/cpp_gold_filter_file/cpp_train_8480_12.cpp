#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T modinv(T a, T n) {
  T i = n, v = 0, d = 1;
  while (a > 0) {
    T t = i / a, x = a;
    a = i % x;
    i = x;
    x = d;
    d = v - t * x;
    v = x;
  }
  return (v + n) % n;
}
long long modpow(long long n, long long k, long long mod) {
  long long ans = 1;
  while (k > 0) {
    if (k & 1) ans = (ans * n) % mod;
    k >>= 1;
    n = (n * n) % mod;
  }
  return ans % mod;
}
template <class T>
string str(T Number) {
  string Result;
  ostringstream convert;
  convert << Number;
  Result = convert.str();
  return Result;
}
int StringToNumber(const string &Text) {
  istringstream ss(Text);
  int result;
  return ss >> result ? result : 0;
}
template <class T>
inline vector<pair<T, int> > FACTORISE(T n) {
  vector<pair<T, int> > R;
  for (T i = 2; n > 1;) {
    if (n % i == 0) {
      int C = 0;
      for (; n % i == 0; C++, n /= i)
        ;
      R.push_back(make_pair(i, C));
    }
    i++;
    if (i > n / i) i = n;
  }
  if (n > 1) R.push_back(make_pair(n, 1));
  return R;
}
template <class T>
inline T TOTIENT(T n) {
  vector<pair<T, int> > R = FACTORISE(n);
  T r = n;
  for (int i = 0; i < R.size(); i++) r = r / R[i].first * (R[i].first - 1);
  return r;
}
template <class T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
double rnd(float d) { return floor(d + 0.49); }
int gems[30005];
int dp[30005][600];
int d;
int maxgems(int start, int length) {
  int offset = length - d + 250;
  if (length == 0) return 0;
  if (start < 0 || start > 30000) return 0;
  if (dp[start][offset] != -1) return dp[start][offset];
  int ans = 0;
  ans = max(ans, maxgems(start + length, length));
  ans = max(ans, maxgems(start + length, length + 1));
  ans = max(ans, maxgems(start + length, length - 1));
  ans += gems[start];
  return dp[start][offset] = ans;
}
int main() {
  int n;
  cin >> n >> d;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    gems[x] += 1;
  }
  cout << maxgems(0, d) << endl;
  return 0;
}
