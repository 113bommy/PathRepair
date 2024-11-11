#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
inline long long int GCD(long long int x, long long int y) {
  if (x < y) swap(x, y);
  if (x == 0) return y;
  if (y == 0) return x;
  return GCD(x % y, y);
}
long long int phi(long long int n) {
  long long int result = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
long long int power(long long int x, long long int n, long long int mod) {
  long long int res = 1;
  x %= mod;
  while (n) {
    if (n & 1) {
      res = ((res * x) % mod + mod) % mod;
    }
    x = ((x * x) % mod + mod) % mod;
    n >>= 1;
  }
  return res;
}
const int MAXN = 1e5 + 5;
long long int N, M;
long long int A[MAXN], B[MAXN];
class DSU {
 public:
  long long int N;
  vector<long long int> parent, sz;
  DSU(long long int N) {
    this->N = N + 5;
    parent.assign(N + 2, 0);
    sz.assign(N + 2, 1);
    for (long long int i = 1; i <= N; i++) parent[i] = i;
  }
  long long int find_parent(long long int x) {
    while (x != parent[x]) {
      x = parent[parent[x]];
    }
    return x;
  }
  bool merge(long long int x, long long int y) {
    long long int a = find_parent(x);
    long long int b = find_parent(y);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    parent[b] = parent[a];
    return true;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> M >> N;
  for (long long int i = 0; i < M; i++) {
    cin >> A[i];
  }
  for (long long int i = 0; i < N; i++) {
    cin >> B[i];
  }
  vector<pair<long long int, pair<long long int, long long int> > > edges;
  long long int k, x;
  for (long long int i = 0; i < M; i++) {
    cin >> k;
    for (long long int j = 0; j < k; j++) {
      cin >> x;
      edges.push_back(make_pair(A[i] + B[x - 1], make_pair(x, i + N + 1)));
    }
  }
  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());
  DSU dsu(N + M + 5);
  long long int ans = 0;
  for (long long int i = 0; i < edges.size(); i++) {
    if (!dsu.merge(edges[i].second.first, edges[i].second.second)) {
      ans += edges[i].first;
    }
  }
  cout << ans << endl;
}
