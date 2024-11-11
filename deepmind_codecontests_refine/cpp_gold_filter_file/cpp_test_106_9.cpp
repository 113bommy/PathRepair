#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
long long INFF = 1000000000000000005ll;
const int mod = 1000000007;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int dx2[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy2[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const int N = 100010;
long long n, m, k, q;
long long dp[N], a[N];
vector<pair<long long, long long> > adj[N];
bool vis[N];
long long dist[N], deg[N];
struct Edge {
  int a, b, c;
  bool operator<(const Edge& w) const { return c < w.c; }
} edges[N];
int p[N];
int find(int u) {
  if (u != p[u]) p[u] = find(p[u]);
  return p[u];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    a[0] = 2;
    for (int i = 1; i <= n; ++i) {
      a[i] = a[i - 1] + 1;
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << "\n";
  }
  return 0;
}
