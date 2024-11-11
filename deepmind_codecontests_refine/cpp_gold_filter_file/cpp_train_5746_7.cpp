#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const unordered_set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const unordered_map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  long long idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
long long n, m;
vector<vector<pair<long long, long long> > > arr(200001);
vector<vector<long long> > cycle(50);
long long visited[200001];
long long cnt = 0;
long long dp[45][200001];
template <int MOD>
struct mod_int {
  static const int mod = MOD;
  unsigned x;
  mod_int() : x(0) {}
  mod_int(int sig) {
    int sigt = sig % MOD;
    if (sigt < 0) sigt += MOD;
    x = sigt;
  }
  mod_int(long long sig) {
    int sigt = sig % MOD;
    if (sigt < 0) sigt += MOD;
    x = sigt;
  }
  int get() const { return (int)x; }
  mod_int& operator+=(mod_int that) {
    if ((x += that.x) >= MOD) x -= MOD;
    return *this;
  }
  mod_int& operator-=(mod_int that) {
    if ((x += MOD - that.x) >= MOD) x -= MOD;
    return *this;
  }
  mod_int& operator*=(mod_int that) {
    x = (unsigned long long)x * that.x % MOD;
    return *this;
  }
  mod_int& operator/=(mod_int that) { return *this *= that.inverse(); }
  mod_int operator+(mod_int that) const { return mod_int(*this) += that; }
  mod_int operator-(mod_int that) const { return mod_int(*this) -= that; }
  mod_int operator*(mod_int that) const { return mod_int(*this) *= that; }
  mod_int operator/(mod_int that) const { return mod_int(*this) /= that; }
  mod_int inverse() const {
    long long a = x, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return mod_int(u);
  }
};
template <int MOD>
istream& operator>>(istream& is, mod_int<MOD>& val) {
  long long x;
  is >> x;
  val = x;
  return is;
}
template <int MOD>
ostream& operator<<(ostream& os, const mod_int<MOD>& val) {
  os << val.get();
  return os;
}
using mint7 = mod_int<1000000007>;
using mint21 = mod_int<1000000021>;
template <typename T>
vector<T> xor_convolution(vector<T> a, vector<T> b) {
  int n = a.size();
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = a[j], y = a[j | i];
        a[j] = x + y, a[j | i] = x - y;
      }
    }
  }
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = b[j], y = b[j | i];
        b[j] = x + y, b[j | i] = x - y;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] *= b[i];
  }
  T inv2 = T(1) / T(2);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        T x = a[j], y = a[j | i];
        a[j] = (x + y) * inv2, a[j | i] = (x - y) * inv2;
      }
    }
  }
  return a;
}
bool cyclefinding(long long u, long long v, long long par) {
  long long p = visited[u];
  visited[u] = 3;
  for (auto x : arr[u]) {
    if (x.first != par and visited[x.first] == 2) {
      if (x.first == v) {
        cycle[cnt].push_back(x.second);
        visited[u] = p;
        return 1;
      }
      if (cyclefinding(x.first, v, u)) {
        cycle[cnt].push_back(x.second);
        visited[u] = p;
        return 1;
      }
    }
  }
  visited[u] = p;
  return 0;
}
void dfs(long long u, long long par) {
  visited[u] = 2;
  for (auto v : arr[u]) {
    if (v.first != par) {
      if (visited[v.first] == 2) {
        cycle[cnt].push_back(v.second);
        cyclefinding(v.first, u, 0);
        cnt++;
      } else if (visited[v.first] == 0) {
        dfs(v.first, u);
      }
    }
  }
  visited[u] = 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  long long i;
  long long xorr = 0;
  for (i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    arr[u].push_back(make_pair(v, w));
    arr[v].push_back(make_pair(u, w));
    xorr ^= w;
  }
  if (m == n - 1) {
    cout << xorr << " 1";
    return 0;
  }
  dfs(1, 0);
  vector<vector<long long> > temp(cnt);
  for (i = 0; i < cnt; i++) {
    long long x = 0;
    for (auto v : cycle[i]) x ^= v, xorr ^= v;
    for (auto v : cycle[i]) temp[i].push_back(x ^ v);
  }
  vector<mint7> freq7;
  vector<mint21> freq21;
  for (i = 0; i < (1LL << 17); i++) freq7.push_back(0), freq21.push_back(0);
  freq7[xorr] = 1;
  freq21[xorr] = 1;
  for (i = 0; i < cnt; i++) {
    vector<mint7> temp7((1LL << 17), 0);
    vector<mint21> temp21((1LL << 17), 0);
    for (auto v : temp[i]) temp7[v] += 1, temp21[v] += 1;
    freq7 = xor_convolution(freq7, temp7);
    freq21 = xor_convolution(freq21, temp21);
  }
  for (i = 0; i < (1LL << 17); i++) {
    if (freq7[i].x == 0 && freq21[i].x == 0) {
      continue;
    } else {
      cout << i << " " << freq7[i].x << endl;
      return 0;
    }
  }
}
