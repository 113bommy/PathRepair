#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool s) { return to_string((int)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long double eps = 1e-12;
const int N = 2e6 + 9;
long long a[25][25];
map<long long, int> xors[25][25];
vector<long long> b2[25][25], b1[25][25];
int mid, n, m;
long long k;
void solve1(int r, int c, long long val) {
  val = val ^ a[r][c];
  if (r + c == mid) {
    xors[r][c][val]++;
    return;
  }
  if (r + 1 < n) solve1(r + 1, c, val);
  if (c + 1 < m) solve1(r, c + 1, val);
}
void solve2(int r, int c, long long val) {
  val = val ^ a[r][c];
  if (r + c == mid) {
    b2[r][c].push_back(val);
    return;
  }
  if (r > 0) solve2(r - 1, c, val);
  if (c > 0) {
    solve2(r, c - 1, val);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  if (n + m == 2) {
    return cout << (k == a[0][0]) << endl, 0;
  }
  mid = (n + m - 2) / 2;
  solve1(0, 0, 0);
  solve2(n - 1, m - 1, 0);
  long long cnt = 0;
  for (int r = 0; r <= mid; r++) {
    int c = mid - r;
    for (int i = 0; i < b2[r][c].size(); i++) {
      long long tof = k ^ b2[r][c][i] ^ a[r][c];
      if (xors[r][c].count(tof)) cnt += xors[r][c][tof];
    }
  }
  cout << cnt << endl;
  return 0;
}
