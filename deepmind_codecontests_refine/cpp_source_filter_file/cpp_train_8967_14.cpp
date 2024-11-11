#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
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
const int N = 3e5 + 20;
const long long oo = 1e18 + 20;
const int MOD = 1e6 + 3;
int mul(int a, int b) { return 1ll * a * b % MOD; }
int add(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
int sub(int a, int b) { return a - b >= 0 ? a - b : a - b + MOD; }
int fpow(int b, int e) {
  int ans = 1;
  for (; e; b = mul(b, b), e >>= 1)
    if (e & 1) ans = mul(ans, b);
  return ans;
}
int inv(int x) { return fpow(x, MOD - 2); }
int divide(int a, int b) { return mul(a, inv(b)); }
const int EPS = 1;
int gauss(vector<vector<int>> a, vector<int> &ans) {
  int n = a.size();
  int m = a[0].size() - 1;
  vector<int> where(m, -1);
  for (int col = 0, row = 0; col < m && row < n; ++col) {
    int sel = row;
    for (int i = row; i < n; ++i)
      if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
    if (abs(a[sel][col]) < EPS) continue;
    for (int i = col; i <= m; ++i) swap(a[sel][i], a[row][i]);
    where[col] = row;
    for (int i = 0; i < n; ++i)
      if (i != row) {
        int c = divide(a[i][col], a[row][col]);
        for (int j = col; j <= m; ++j)
          a[i][j] = sub(a[i][j], mul(a[row][j], c));
      }
    ++row;
  }
  ans.assign(m, 0);
  for (int i = 0; i < m; ++i)
    if (where[i] != -1) ans[i] = divide(a[where[i]][m], a[where[i]][i]);
  for (int i = 0; i < n; ++i) {
    double sum = 0;
    for (int j = 0; j < m; ++j) sum = add(sum, mul(ans[j], a[i][j]));
    if (sum != a[i][m]) return 0;
  }
  for (int i = 0; i < m; ++i)
    if (where[i] == -1) return -1;
  return 1;
}
int test(vector<int> &pol) {
  42;
  for (int i = 0; i < MOD; i++) {
    int sum = 0, p = 1;
    for (int j = 0; j < (int)pol.size(); j++) {
      sum = add(sum, mul(pol[j], p));
      p = mul(i, p);
    }
    if (sum == 0) return i;
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> cur;
  for (int k = 1; k <= 10; k++) {
    cout << "? " << k - 1 << endl;
    int x;
    cin >> x;
    cur.push_back(x);
    vector<vector<int>> a(k, vector<int>(k + 1));
    for (int i = 0; i < (int)cur.size(); i++) {
      int p = 1;
      for (int j = 0; j <= k; j++) {
        if (j == 0)
          a[i][j] = 1;
        else if (j == k)
          a[i][j] = cur[i];
        else {
          p = mul(p, i);
          a[i][j] = p;
        }
      }
    }
    vector<int> ans;
    int t = gauss(a, ans);
    if (t == 0) continue;
    int y = test(ans);
    if (y == -1) continue;
    cout << "? " << y << endl;
    cin >> x;
    if (x == 0) {
      cout << "! " << y << endl;
      return 0;
    }
  }
  cout << "! " << -1 << endl;
}
