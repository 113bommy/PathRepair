#include <bits/stdc++.h>
using namespace std;
const int maxn = 5050;
int n, m;
vector<int> group[maxn];
int gol[maxn], gor[maxn];
const int mod = 1e9 + 7;
int a[maxn];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    int id, x;
    cin >> id >> x;
    int j = 1;
    for (int t = x; j <= n; j++) {
      if (a[j] == id) t--;
      if (!t) break;
    }
    gor[i] = j;
    j = n;
    for (int t = x; j; j--) {
      if (a[j] == id) t--;
      if (!t) break;
    }
    gol[i] = j;
    group[id].emplace_back(i);
  }
  int mx = 0;
  auto check = [&](int x, int y, int z) {
    if (x + y == 0) return 0;
    if (x == 0 || y == 0) return 1;
    if (x + y == 2 && z == 1) return 1;
    return 2;
  };
  auto cal = [&](int i) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      int x = 0, y = 0, z = 0;
      int f1 = 0, f2 = 0;
      for (auto k : group[j]) {
        if (gor[k] <= i) x++;
        if (gol[k] > i) y++;
        if (gor[k] <= i && gol[k] > i) z++;
        if (gor[k] == i) {
          f1++;
          if (gol[k] > i) f2++;
        }
      }
      if (a[i] == j) {
        if (f2 * (y - 1) + (f1 - f2) * y > 0) {
          sum += 2;
        } else if (f1 > 0) {
          sum++;
        } else
          return -1;
      } else {
        if (check(x, y, z) == 2) {
          sum += 2;
        } else if (check(x, y, z) == 1)
          sum++;
      }
    }
    return sum;
  };
  auto getans = [&](int l, int r) {
    int res = 1;
    for (int j = 1; j <= n; j++) {
      if (group[j].empty()) {
        if (a[l] == j) res = 0;
        continue;
      }
      int x = 0, y = 0, z = 0;
      int f1 = 0, f2 = 0;
      for (auto k : group[j]) {
        if (gor[k] <= l) x++;
        if (gol[k] >= r) y++;
        if (gor[k] <= l && gol[k] >= r) z++;
        if (gor[k] == l) {
          f1++;
          if (gol[k] >= r) f2++;
        }
      }
      if (a[l] == j) {
        if (f2 * (y - 1) + (f1 - f2) * y > 0) {
          res = 1ll * res * (f2 * (y - 1) + (f1 - f2) * y) % mod;
        } else if (f1 > 0) {
          res = 1ll * res * f1 % mod;
        } else
          return 0;
      } else {
        if (check(x, y, z) == 2) {
          res = 1ll * res * (x * y - z * z) % mod;
        } else if (check(x, y, z) == 1) {
          res = 1ll * res * (x + y) % mod;
        }
      }
    }
    return res;
  };
  for (int i = 0; i <= n; i++) {
    int sum = cal(i);
    mx = max(mx, sum);
  }
  int res = 0;
  vector<int> s;
  for (int i = 0; i <= n; i++) {
    if (cal(i) != mx)
      continue;
    else
      s.emplace_back(i);
    res = (res + getans(i, i + 1)) % mod;
  }
  if (mx == 0) res = 1;
  cout << mx << " " << res << "\n";
  return 0;
}
