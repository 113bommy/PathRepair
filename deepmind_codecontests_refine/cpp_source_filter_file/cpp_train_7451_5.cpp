#include <bits/stdc++.h>
const long double EPS = 1e-10;
const int MOD = 1000000007ll;
const int mod1 = 1000000009ll;
const int mod2 = 1100000009ll;
int INF = (int)1e9;
long long int INFINF = (long long int)1e18;
int debug = 0;
long double PI = acos(-1.0);
using namespace std;
int bit_count(long long int _x) {
  long long int _ret = 0;
  while (_x) {
    if (_x % 2 == 1) _ret++;
    _x /= 2;
  }
  return _ret;
}
int bit(long long int _mask, int _i) {
  return (_mask & (1ll << _i)) == 0 ? 0 : 1;
}
int add(int a, int b, int m = MOD) {
  int x = a + b;
  while (x >= m) x -= m;
  while (x < 0) x += m;
  return x;
}
int sub(int a, int b, int m = MOD) {
  int x = a - b;
  while (x < 0) x += m;
  while (x >= m) x -= m;
  return x;
}
int mul(int a, int b, int m = MOD) {
  long long int x = a * 1ll * b;
  x %= m;
  while (x < 0) x += m;
  return (int)x;
}
int ldtoint(long double x) { return (int)(x + 0.5); }
long long int ldtolli(long double x) { return (long long int)(x + 0.5); }
int powermod(long long int _a, long long int _b, int _m = MOD) {
  long long int _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = mul(_r, _a, _m);
    _b >>= 1;
    _a = mul(_a, _a, _m);
  }
  return _r;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  os << "[" << p.first << "," << p.second << "]";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  bool first = true;
  for (T it : v) {
    if (!first) os << ", ";
    first = false;
    os << it;
  }
  os << "]";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, set<T>& v) {
  os << "[";
  bool first = true;
  for (T it : v) {
    if (!first) os << ", ";
    first = false;
    os << it;
  }
  os << "]";
  return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, map<T1, T2>& v) {
  os << "[";
  bool first = true;
  for (pair<T1, T2> it : v) {
    if (!first) os << ", ";
    first = false;
    os << "(" << it.first << "," << it.second << ")";
  }
  os << "]";
  return os;
}
template <class T>
void parr(T a[], int s, int e) {
  cout << "[";
  for (int i = s; i < e; i++) cout << a[i] << ", ";
  cout << a[e] << "]\n";
}
struct UnionFind {
  static const int MAXN = 100010;
  int parent[MAXN];
  int val[MAXN];
  vector<int> G[MAXN];
  void init(int N) {
    for (int i = 1; i <= N; i++) {
      parent[i] = i;
      G[i].clear();
      G[i].push_back(i);
      val[i] = 0;
    }
  }
  int Find(int u) {
    if (parent[u] != u) parent[u] = Find(parent[u]);
    return parent[u];
  }
  void Union(int u, int v, int type) {
    int pv = Find(v);
    int pu = Find(u);
    if (G[pv].size() > G[pu].size()) swap(pu, pv);
    parent[pv] = pu;
    bool fff1 = (val[u] != val[v]);
    bool fff2 = (val[u] == val[v]);
    for (int it : G[pv]) {
      G[pu].push_back(it);
      if (type == 1 && fff1) val[it] = 1 - val[it];
      if (type == 2 && fff2) val[it] = 1 - val[it];
    }
  }
};
int N, M, Q;
map<string, int> Map;
UnionFind UF;
int main() {
  if (0) {
    freopen("input.txt", "r", stdin);
    debug = 1;
  }
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> Q;
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    Map[s] = i;
  }
  UF.init(N);
  for (int i = 1; i <= M; i++) {
    int t, u, v;
    string s1, s2;
    cin >> t >> s1 >> s2;
    u = Map[s1];
    v = Map[s2];
    if (UF.Find(u) == UF.Find(v)) {
      if (UF.val[u] == UF.val[v] && t == 1) {
        cout << "YES\n";
      } else if (UF.val[u] != UF.val[v] && t == 2) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      UF.Union(u, v, t);
      cout << "YES2\n";
    }
  }
  while (Q--) {
    int u, v;
    string s1, s2;
    cin >> s1 >> s2;
    u = Map[s1];
    v = Map[s2];
    if (UF.Find(u) != UF.Find(v))
      cout << "3\n";
    else {
      if (UF.val[u] == UF.val[v])
        cout << "1\n";
      else
        cout << "2\n";
    }
  }
  return 0;
}
