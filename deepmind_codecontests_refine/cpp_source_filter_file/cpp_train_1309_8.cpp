#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << "(" << p.first << "," << p.second << ")";
  return o;
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
  o << "[";
  for (T t : v) {
    o << t << ",";
  }
  o << "]";
  return o;
}
long long mod_pow(long long x, long long n, long long mod) {
  long long res = 1;
  x %= mod;
  while (n > 0) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long mod_inv(long long x, long long mod) {
  return mod_pow(x, mod - 2, mod);
}
int main() {
  long long m, n;
  cin >> m >> n;
  vector<long long> vec(n);
  for (int i = (int)(0); i < (int)(n); i++) scanf("%d", &vec[i]);
  set<long long> st;
  for (int i = (int)(0); i < (int)(n); i++) st.insert(vec[i]);
  if (n == 1) {
    cout << vec[0] << " " << 0;
    return 0;
  }
  if (m < n) {
    cout << -1 << endl;
    return 0;
  }
  if (m == n) {
    cout << vec[0] << " " << 1 << endl;
    return 0;
  }
  long long s = 0;
  for (int i = (int)(0); i < (int)(n); i++) (s += vec[i]) %= m;
  long long ss = 0;
  for (int i = (int)(0); i < (int)(n); i++) (ss += vec[i] * vec[i] % m) %= m;
  long long invnn = mod_inv(n * (n - 1) / 2 % m, m);
  vector<int> idx(n - 1);
  for (int i = (int)(0); i < (int)(n - 1); i++) idx[i] = i + 1;
  random_shuffle((idx).begin(), (idx).end());
  random_shuffle((vec).begin(), (vec).end());
  srand(time(NULL));
  for (int i = (int)(0); i < (int)(n); i++) {
    long long x = vec[i];
    long long d = (s - n * x % m + m) * invnn % m;
    if (d == 0 || d * 2 > m) continue;
    long long f = (n * x * x % m + n * (n - 1) % m * d % m * x % m +
                   n * (n - 1) * (2 * n - 1) / 6 % m * d % m * d % m) %
                  m;
    if (f != ss) continue;
    int cnt = 1;
    while (cnt < n) {
      long long tmp = x + d * idx[cnt - 1];
      if (st.find(tmp % m) == st.end()) break;
      tmp += d;
      cnt++;
    }
    if (cnt == n) {
      cout << x << " " << d << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
