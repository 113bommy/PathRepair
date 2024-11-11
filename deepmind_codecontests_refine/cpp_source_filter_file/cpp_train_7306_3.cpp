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
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
int k;
vector<pair<int, int>> prime_factorize(int a) {
  vector<pair<int, int>> ret;
  if (a == 1) return ret;
  for (int p = 2; p * p <= a; p++) {
    int i = 0;
    if (a % p == 0) {
      while (a % p == 0) {
        a = a / p;
        i++;
      }
      if (i % k != 0) ret.push_back(make_pair(p, i));
    }
  }
  if (a > 1) {
    ret.push_back(make_pair(a, 1));
  }
  for (auto &t : ret) {
    int l = t.second;
    l = (l % k + k) % k;
    t.second = l;
  }
  return ret;
}
void solve() {
  int n;
  cin >> n >> k;
  vector<int> a(n);
  vector<vector<pair<int, int>>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vector<pair<int, int>> temp = prime_factorize(a[i]);
    p[i] = temp;
  }
  map<vector<pair<int, int>>, int> countmap;
  vector<vector<pair<int, int>>> q(n);
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> t1 = p[i];
    countmap[t1]++;
    for (auto &t : t1) {
      t.second = k - t.second;
    }
    q[i] = t1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> t1 = p[i];
    for (auto &t : t1) {
      t.second = k - t.second;
    }
    ans += countmap[t1];
    if (p[i] == t1) ans--;
  }
  cout << ans / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  while (test--) solve();
  return 0;
}
