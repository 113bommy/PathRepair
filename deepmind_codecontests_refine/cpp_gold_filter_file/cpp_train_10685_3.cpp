#include <bits/stdc++.h>
using namespace std;
const unsigned long long inf = (1ll << 61);
const unsigned long long mod = 1e9 + 7;
const int MX = 5009;
int n, k, v, a[MX], dp[MX][MX][2];
vector<int> sol;
unsigned long long sum = 0;
vector<pair<int, pair<int, int> > > res;
int DP(int x, int y, bool flag = 0) {
  if (x == n + 1) {
    if (!flag) return 0;
    if (y != v % k) return 0;
    return 1;
  }
  int &ret = dp[x][y][2];
  if (ret != -1) return ret;
  ret = DP(x + 1, y, flag);
  return ret = max(ret, DP(x + 1, (y + a[x]) % k, 1));
}
void FDP(int x, int y, bool flag = 0) {
  if (x == n + 1) return;
  int &ret = dp[x][y][2];
  if (DP(x + 1, y, flag)) {
    FDP(x + 1, y, flag);
    return;
  }
  sol.push_back(x);
  FDP(x + 1, (y + a[x]) % k, 1);
  return;
}
int main() {
  cin >> n >> k >> v;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
  if (sum < v) {
    puts("NO");
    return 0;
  }
  if (v == 0) {
    if (n == 1) {
      puts("NO");
      return 0;
    }
    puts("YES");
    cout << 1e5 << " " << 1 << " " << 2 << endl;
    return 0;
  }
  memset(dp, -1, sizeof(dp));
  int tmp = v % k;
  if (DP(1, 0, 0) == 0 && tmp) {
    puts("NO");
    return 0;
  }
  if (!tmp) {
    puts("YES");
    cout << 1e5 << " " << 1 << " " << 2 << endl;
    for (int i = 3; i <= n; i++) cout << 1e5 << " " << i << " " << 2 << endl;
    if (v / k) cout << v / k << " " << 2 << " " << 1 << endl;
    return 0;
  }
  FDP(1, 0, 0);
  int tank = sol[0], need;
  for (int i = 1; i < sol.size(); i++) {
    res.push_back({1e5, {sol[i], tank}});
    a[tank] += a[sol[i]];
    a[sol[i]] = 0;
  }
  if (a[tank] == v) {
    puts("YES");
    for (auto pp : res)
      cout << pp.first << " " << pp.second.first << " " << pp.second.second
           << endl;
    return 0;
  }
  int tank1 = 1;
  if (tank == 1) tank1 = 2;
  if (a[tank] > v) {
    int diff = a[tank] - v;
    diff /= k;
    if (tank == 1)
      res.push_back({diff, {1, 2}});
    else
      res.push_back({diff, {tank, 1}});
    puts("YES");
    for (auto pp : res)
      cout << pp.first << " " << pp.second.first << " " << pp.second.second
           << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!a[i] || i == tank || i == tank1) continue;
    res.push_back({1e5, {i, tank1}});
    a[tank1] += a[i];
  }
  need = v - a[tank];
  need /= k;
  int x = a[tank1] / k;
  if (x < need) {
    puts("NO");
    return 0;
  }
  res.push_back({need, {tank1, tank}});
  puts("YES");
  for (auto pp : res)
    cout << pp.first << " " << pp.second.first << " " << pp.second.second
         << endl;
}
