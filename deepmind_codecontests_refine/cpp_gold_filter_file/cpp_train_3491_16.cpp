#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "[";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &t) {
  os << "{";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "}";
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;
template <int N, int MOD>
struct Comb {
  long long int fact[N + 1], inv[N + 1];
  Comb() {
    fact[0] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= N; i++)
      inv[i] = (MOD + ((long long int)-inv[MOD % i] * (MOD / i)) % MOD) % MOD;
    for (int i = 1; i <= (int)(N); i++) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = inv[i] * inv[i - 1] % MOD;
    }
  }
  long long int operator()(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    long long int res = inv[r] * inv[n - r];
    if (res >= MOD) res %= MOD;
    res *= fact[n];
    if (res >= MOD) res %= MOD;
    return res;
  }
};
Comb<300000, MOD> C;
inline long long int mod_inverse(long long int a, long long int m) {
  long long int b = m, u = 1, v = 0;
  while (b) {
    long long int t = a / b;
    swap(a -= t * b, b);
    swap(u -= t * v, v);
  }
  return (u % m + m) % m;
}
long long int modpow(long long int x, long long int y) {
  if (y < 0) return modpow(mod_inverse(x, MOD), -y);
  long long int r = 1, a = x % MOD;
  while (y > 0) {
    if ((y & 1) == 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    y /= 2;
  }
  return r;
}
int n, m;
const long long int inv26 = 25ll * 576923081 % MOD;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m;
  string s;
  map<int, vector<pair<int, int>>> mp;
  int qc = 0;
  for (int i = 0; i < (int)(m + 1); i++) {
    int t = 1;
    if (i) cin >> t;
    if (t == 1) {
      string s;
      cin >> s;
      n = s.size();
    } else {
      int x;
      cin >> x;
      mp[n].emplace_back(x, qc++);
    }
  }
  vector<int> ans(qc);
  for (auto it : mp) {
    int n = it.first;
    auto v = it.second;
    sort((v).begin(), (v).end());
    long long int y = 0;
    long long int t = modpow(inv26, n);
    for (int j = n, i = 0; i < v.size(); j++) {
      y += t * C(j - 1, n - 1) % MOD;
      t = t * inv26 % MOD;
      while (i < v.size() && j >= v[i].first) {
        int x, k;
        tie(x, k) = v[i++];
        if (j > x) continue;
        ans[k] = y % MOD * modpow(26, x) % MOD * modpow(25, -n) % MOD;
      }
    }
  }
  for (int x : ans) cout << x << endl;
  return 0;
}
