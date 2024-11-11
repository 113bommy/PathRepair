#include <bits/stdc++.h>
using namespace std;
using lld = int64_t;
using llu = uint64_t;
using llf = long double;
using PII = pair<int, int>;
using PIL = pair<int, lld>;
using PLI = pair<lld, int>;
using PLL = pair<lld, lld>;
template <typename T>
using maxHeap = priority_queue<T, vector<T>, less<T>>;
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename Iter>
ostream& _out(ostream& s, Iter b, Iter e) {
  s << "[";
  for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
  s << "]";
  return s;
}
template <typename A, typename B>
ostream& operator<<(ostream& s, const pair<A, B>& p) {
  return s << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, const vector<T>& c) {
  return _out(s, begin(c), end(c));
}
bool debug = 0;
template <typename T>
void DEBUG(const T& x) {
  if (debug) cerr << x;
}
template <typename T, typename... Args>
void DEBUG(const T& head, const Args&... tail) {
  if (debug) {
    cerr << head;
    DEBUG(tail...);
  }
}
const int N = 2000 + 5;
const int Z = 26 + 3;
int a[N][N];
int u[Z], d[Z], l[Z], r[Z];
int main(int argc, char* argv[]) {
  if (argc > 1 && string(argv[1]) == "-D") debug = 1;
  if (!debug) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  }
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if ('a' <= s[j] and s[j] <= 'z')
          a[i + 1][j + 1] = s[j] - 'a' + 1;
        else
          a[i + 1][j + 1] = 0;
      }
    }
    for (int i = 1; i <= 26; ++i)
      u[i] = n + 1, d[i] = 0, l[i] = m + 1, r[i] = 0;
    for (int i = 0; i <= n + 1; ++i) a[i][m + 1] = 0;
    for (int j = 0; j <= m + 1; ++j) a[n + 1][j] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) u[a[i][j]] = min(u[a[i][j]], i);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) d[a[i][j]] = max(d[a[i][j]], i);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) l[a[i][j]] = min(l[a[i][j]], j);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) r[a[i][j]] = max(r[a[i][j]], j);
    int mx = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) mx = max(mx, a[i][j]);
    vector<pair<PII, PII>> ans;
    bool flag = true;
    for (int i = mx; i >= 1; --i) {
      if (u[i] == n + 1) {
        ans.push_back({{u[mx], l[mx]}, {u[mx], l[mx]}});
        continue;
      }
      if (l[i] == r[i]) {
        for (int x = u[i]; x <= d[i]; ++x) flag &= (a[x][l[i]] >= i);
        if (not flag) break;
        ans.push_back({{u[i], l[i]}, {d[i], r[i]}});
      } else if (u[i] == d[i]) {
        for (int y = l[i]; y <= r[i]; ++y) flag &= (a[u[i]][y] >= i);
        if (not flag) break;
        ans.push_back({{u[i], l[i]}, {d[i], r[i]}});
      } else {
        flag = false;
        break;
      }
    }
    if (not flag) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    cout << mx << '\n';
    reverse(begin(ans), end(ans));
    for (auto p : ans)
      cout << p.first.first << ' ' << p.first.second << ' ' << p.second.first
           << ' ' << p.second.second << '\n';
  }
  return 0;
}
