#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const long long mod = 1000000007;
const int base = 311;
int n, k, m, a, g[105], b[105], r[105];
int lt[105], rt[105];
struct three {
  int a, b, c;
  three() {}
  three(int _a, int _b, int _c) {
    a = _a;
    b = _b;
    c = _c;
  }
  bool operator<(const three &other) const {
    return (a > other.a || (a == other.a && b < other.b));
  }
};
void solve(int id) {
  int mx = 0;
  vector<three> rate(0);
  for (int i = 1; i <= n; ++i) {
    if (i == id) {
      if (a == m)
        rate.push_back(three(b[i] + m - a, r[i], i));
      else
        rate.push_back(three(b[i] + m - a, n, i));
    } else
      rate.push_back(three(b[i], r[i], i));
  }
  sort((rate).begin(), (rate).end());
  for (int i = 0; i < n; ++i) {
    if (rate[i].c == id) {
      mx = i + 1;
      if (rate[i].a == 0) {
        cout << 3 << ' ';
        return;
      }
    }
  }
  rate.clear();
  for (int i = 1; i <= n; ++i) {
    rate.push_back(three(b[i], r[i], i));
  }
  sort((rate).begin(), (rate).end());
  int idx;
  for (int i = 0; i < n; ++i) {
    if (rate[i].c == id) idx = i;
  }
  int mn = idx + 1, remain = m - a;
  for (int i = idx + 1; i < n; ++i) {
    int need = b[rate[idx].c] - b[rate[i].c] + 1;
    if (need > remain) break;
    remain -= need;
    ++mn;
  }
  if (b[id] == 0) {
    if (mx <= k)
      cout << 2;
    else
      cout << 3;
    cout << ' ';
    return;
  }
  if (mn <= k)
    cout << 1;
  else if (mx > k)
    cout << 3;
  else
    cout << 2;
  cout << ' ';
}
void gogo() {
  cin >> n >> k >> m >> a;
  for (int i = 1; i <= a; ++i) {
    cin >> g[i];
    b[g[i]]++;
    r[g[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    solve(i);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("sol"
            ".inp",
            "r")) {
    freopen(
        "sol"
        ".inp",
        "r", stdin);
    freopen(
        "sol"
        ".out",
        "w", stdout);
  }
  gogo();
}
