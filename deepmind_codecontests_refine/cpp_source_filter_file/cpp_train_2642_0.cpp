#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
template <class T>
T round_up(T a, T b) {
  return (a + b - 1) / b;
}
template <class T>
void uniq(vector<T>& c) {
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
}
template <class T>
string to_s(const T& a) {
  ostringstream os;
  os << a;
  return os.str();
}
template <class T>
T to_T(const string& s) {
  istringstream is(s);
  T res;
  is >> res;
  return res;
}
template <class T, class U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
  os << "( " << p.first << ", " << p.second << " )";
  return os;
}
template <class T>
void print(T a, int n, const string& deli = " ", int br = 1) {
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i + 1 != n) cout << deli;
  }
  while (br--) cout << endl;
}
template <class T>
void print(const T& c, const string& deli = " ", int br = 1) {
  for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it) {
    cout << *it;
    if (++it != c.end()) cout << deli;
    --it;
  }
  while (br--) cout << endl;
}
template <class T>
void print2d(T a, int w, int h, int width = -1, int br = 1) {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (width != -1) cout.width(width);
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  while (br--) cout << endl;
}
template <class T>
void input(T& a, int n) {
  for (int i = 0; i < n; ++i) cin >> a[i];
}
template <class T>
void input(T* a, int n) {
  for (int i = 0; i < n; ++i) cin >> a[i];
}
void fix_pre(int n) {
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(10);
}
void fast_io() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}
bool in_rect(int x, int y, int w, int h) {
  return 0 <= x && x < w && 0 <= y && y < h;
}
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const double PI = acos(-1.0);
const int M = 3 * ((long long)(1e5));
vector<int> g[M];
int s[M];
void dfs(int v) {
  int enemy = 0;
  for (int i = 0; i < (int)(g[v].size()); ++i)
    if (s[v] == s[g[v][i]]) ++enemy;
  if (enemy == 2) {
    s[v] ^= 1;
    for (int i = 0; i < (int)(g[v].size()); ++i) dfs(g[v][i]);
  }
}
int main() {
  fast_io();
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < (int)(n); ++i) dfs(i);
  string res;
  for (int i = 0; i < (int)(n); ++i) res += '0' + s[i];
  cout << res << endl;
}
