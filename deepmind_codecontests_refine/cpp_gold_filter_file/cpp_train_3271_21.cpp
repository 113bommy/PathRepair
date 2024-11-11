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
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  map<pair<int, int>, int> ma;
  vector<vector<int> > a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int l = j + 1; l < m; l++) {
        if (k == 1) {
          if (a[i][j] < a[i][l]) {
            ma[make_pair(l, j)]++;
          }
        } else {
          if (a[i][j] > a[i][l]) {
            ma[make_pair(j, l)]++;
          }
        }
      }
    }
  }
  cout << ((int)(ma).size()) << "\n";
  map<pair<int, int>, int>::iterator it;
  for (it = ma.begin(); it != ma.end(); it++) {
    cout << (it->first).first + 1 << " " << (it->first).second + 1 << "\n";
  }
  return 0;
}
