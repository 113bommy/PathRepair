#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long p = 997;
const long long base = 1e9 + 7;
const long long MAXN = 5e5;
const long long INF = 1e9;
const long long MOD = 1e9;
const double PII = 3.14159265358979323846264338327950288419716939937510;
const double Epsilon = 1.19209e-9;
const long double fi = 1.6180339887498948482;
const long long one = 2147483647;
const long long two = 1e9 + 7;
void print_vector(vector<long long>& a) {
  for (int i = 0; i < (long long)a.size(); ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
void read_vector(vector<long long>& a, long long n) {
  long long h;
  for (int i = 0; i < n; ++i) {
    cin >> h;
    a.push_back(h);
  }
}
bool check_four(int a) {
  int sum = 0;
  while (a) {
    sum += a % 10;
    a /= 10;
  }
  return sum % 4 == 0;
}
void upd_max(int& a, int b) { a = max(a, b); }
void upd_min(int& a, int b) { a = min(a, b); }
vector<int> f(MAXN);
struct Edge {
  int v, to, w;
  Edge(int a, int b, int c) : v(a), to(b), w(c) {}
  bool operator<(const Edge other) const { return (*this).w < other.w; }
};
int get_tsar(int u) {
  if (u == f[u]) {
    return u;
  }
  return f[u] = get_tsar(f[u]);
}
bool Union(int u, int v) {
  u = get_tsar(u);
  v = get_tsar(v);
  if (u == v) return false;
  f[v] = u;
  return true;
}
int main() {
  int n, m;
  for (int i = 0; i < MAXN; ++i) f[i] = i;
  cin >> n >> m;
  vector<Edge> gg;
  int from, tom, hom, m1 = 1e9, m2 = 1e9;
  cin >> from >> tom >> hom;
  for (int i = 0; i < m - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    gg.push_back({a, b, c});
    if (a == from || a == tom) {
      m1 = min(m1, c);
    }
    if (b == from || b == tom) {
      m2 = min(m2, c);
    }
  }
  if (gg.size()) sort(gg.begin(), gg.end());
  for (int i = 0; i < m - 1; ++i) {
    int last = gg[i].w;
    Union(gg[i].v, gg[i].to);
    if (get_tsar(from) == get_tsar(tom)) {
      cout << last;
      return 0;
    }
  }
  cout << 1000000000;
  return 0;
}
