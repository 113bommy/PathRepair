#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
const int base = 400;
int n, m, t, k, T, ans, tong, lab[N], a[N][2], b[N], c[N], st[N], d[N], u, v;
vector<pair<int, int> > adj[N], kq;
string s;
bool cmp(const pair<int, int>& x, const pair<int, int>& y) {
  if (x.first / base == y.first / base) return x.second < y.second;
  return (x.first / base < y.first / base);
}
struct matrix {
  int c[8][8];
  matrix() { memset(c, 0, sizeof(c)); }
};
int pw(int k, int n) {
  int total = 1;
  for (; n; n >>= 1) {
    if (n & 1) total = total * k % mod;
    k = k * k % mod;
  }
  return total;
}
matrix nhan(matrix a, matrix b) {
  matrix res;
  for (int i = 1; i < 6; i++) {
    for (int j = 1; j < 6; j++) {
      for (int k = 1; k < 6; k++) {
        res.c[i][j] = (res.c[i][j] + a.c[i][k] * b.c[k][j] % m) % m;
      }
    }
  }
  return res;
}
int cal(int pos, int len) {
  if (pos > n || pos + len - 1 > n) return 0;
  int val = s[pos + len - 1] - '0';
  if (val == 1 || val == 0) {
    if (a[pos + len - 1][val ^ 1] < pos) return 1 + cal(pos + len, len);
  } else {
    if (min(a[pos + len - 1][0], a[pos + len - 1][1]) < pos)
      return 1 + cal(pos + len, len);
  }
  if (pos + len > n) return 0;
  val = s[pos + len] - '0';
  if (val == 1 || val == 0) {
    return cal(max(pos + 1, a[pos + len][val ^ 1] + 1), len);
  } else
    return cal(max(pos + 1, min(a[pos + len][1], a[pos + len][0]) + 1), len);
}
void sol() {
  cin >> n >> s;
  s = " " + s;
  for (int i = 1; i <= n; i++) {
    a[i][0] = a[i - 1][0];
    a[i][1] = a[i - 1][1];
    if (s[i - 1] == '1')
      a[i][1] = i - 1;
    else if (s[i - 1] == '0')
      a[i][0] = i - 1;
  }
  for (int i = 1; i <= n; i++) cout << cal(1, i) << " ";
}
int main() {
  if (fopen("cowpatibility"
            ".in",
            "r")) {
    freopen(
        "cowpatibility"
        ".in",
        "r", stdin);
    freopen(
        "cowpatibility"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest = 1;
  while (ntest-- > 0) sol();
}
