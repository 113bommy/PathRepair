#include <bits/stdc++.h>
const double eps = 1e-10;
const float epsf = 1e-6;
using namespace std;
inline long long int __gcd(long long int a, long long int b) {
  if (a == 0 || b == 0) {
    return max(a, b);
  }
  long long int tempa, tempb;
  while (1) {
    if (a % b == 0)
      return b;
    else {
      tempa = a;
      tempb = b;
      a = tempb;
      b = tempa % tempb;
    }
  }
}
inline int compfloat(float& x, float& y) {
  if (fabs(x - y) < epsf)
    return 0;
  else if (x - y > 0)
    return 1;
  return -1;
}
inline int compdouble(double x, double y) {
  if (fabs(x - y) < eps)
    return 0;
  else if (x - y > 0)
    return 1;
  else
    return -1;
}
bool prime(long long int k) {
  for (long long int i = 2; i * i <= k; i++)
    if (k % i == 0) {
      return false;
    }
  return true;
}
void pdash(int n = 1) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      cout << "-";
    }
    cout << "\n";
  }
}
long long int power(long long int x, long long int y) {
  long long int result = 1;
  while (y > 0) {
    if (y & 1) {
      result = (result * x);
    }
    y = y >> 1;
    x = (x * x);
  }
  return result;
}
long long int power(long long int x, long long int y, long long int z) {
  long long int result = 1;
  x = x % z;
  while (y > 0) {
    if (y & 1) {
      result = (result * x) % z;
    }
    y = y >> 1;
    x = (x * x) % z;
  }
  return result;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrF(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int f[n + 1];
  f[0] = 1;
  for (long long int i = 1; i <= n; i++) f[i] = f[i - 1] * i % p;
  return (f[n] * modInverse(f[r], p) % p * modInverse(f[n - r], p) % p) % p;
}
void cordinate_compression(vector<int>& v) {
  vector<int> p = v;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  for (int i = 0; i < (int)((v).size()); i++)
    v[i] = (int)(lower_bound(p.begin(), p.end(), v[i]) - p.begin());
}
void solve() {
  long long int xx;
  __uint128_t x;
  cin >> xx;
  x = xx;
  if (x == 1) {
    cout << "1\n1 1\n";
    return;
  }
  vector<pair<__uint128_t, __uint128_t> > ans;
  __uint128_t a, b;
  for (__uint128_t i = 1; i * (i + 1) * (2 * i + 1) <= 6 * x; i++) {
    if (((6 * x) - (i * (i + 1) * (2 * i + 1))) % (3 * i * (i + 1)) == 0) {
      a = ((6 * x) - (i * (i + 1) * (2 * i + 1))) / (3 * i * (i + 1));
      a += i;
      ans.push_back({a, i});
      if (a ^ i) ans.push_back({i, a});
    }
  }
  sort(ans.begin(), ans.end());
  cout << (int)((ans).size()) << "\n";
  for (auto& j : ans) {
    cout << (long long int)j.first << " " << (long long int)j.second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
