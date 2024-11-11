#include <bits/stdc++.h>
using namespace std;
const long long mod = 31607;
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& x : v) {
    in >> x;
  }
  return in;
}
template <class T, class U>
istream& operator>>(istream& in, pair<T, U>& v) {
  in >> v.first >> v.second;
  return in;
}
template <class T, class U>
ostream& operator<<(ostream& out, pair<T, U>& v) {
  out << v.first << " " << v.second;
  return out;
}
template <class T, class U>
void chkmax(T& a, U b) {
  a = max(a, (T)b);
  return;
}
template <class T, class U>
void chkmin(T& a, U b) {
  a = min(a, (T)b);
  return;
}
long long ppow(long long x, long long s) {
  long long res = 1;
  while (s) {
    if (s % 2) {
      (res *= x) %= mod;
    }
    (x *= x) %= mod;
    s /= 2;
  }
  return res;
}
vector<int> zf(string s) {
  int n = int64_t(s.size());
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
vector<int> pf(string p) {
  int n = int64_t(p.size());
  vector<int> pref_fun(n, 0);
  for (int i = 1; i < n; i++) {
    int j = pref_fun[i - 1];
    while (j > 0 && p[i] != p[j]) j = pref_fun[j - 1];
    if (p[i] == p[j]) j++;
    pref_fun[i] = j;
  }
  return pref_fun;
}
vector<vector<int> > mul(vector<vector<int> >& a, vector<vector<int> >& b) {
  int n = int64_t(a.size());
  vector<vector<int> > c(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        long long ga = a[i][k];
        ga *= b[k][j];
        ga %= mod;
        c[i][j] += ga;
        if (c[i][j] >= mod) {
          c[i][j] -= mod;
        }
      }
    }
  }
  return c;
}
vector<vector<int> > matrix_pow(vector<vector<int> > a, long long y) {
  int n = int64_t(a.size());
  vector<vector<int> > res(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) res[i][i] = 1;
  while (y) {
    if (y % 2 == 1) {
      res = mul(res, a);
      y--;
    } else {
      a = mul(a, a);
      y /= 2;
    }
  }
  return res;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<vector<bool> > f(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      f[i][j] = f[j][i] =
          (abs(x[i] - x[j]) % 4 == 0) && (abs(y[i] - y[j]) % 4 == 0);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = i + 1; j < n; j++) {
      if (f[i][j]) {
        ans += n - 2;
        cnt++;
      }
    }
    ans -= cnt * (cnt - 1) / 2;
  }
  cout << ans;
  return 0;
}
