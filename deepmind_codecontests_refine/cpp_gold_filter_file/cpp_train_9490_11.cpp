#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 5e5 + 5;
long long a[maxn];
int c[maxn];
int n;
long long sum = 0;
vector<int> num[maxn];
bool check(int x) {
  int cnt = sum;
  for (int i = 1; i <= n; i++) c[i] = a[i];
  int res = x;
  int tot = 0;
  for (int i = x; i >= 1 && res; i--) {
    for (int j = 0; j < num[i].size(); j++) {
      if (!c[num[i][j]]) continue;
      int u = num[i][j];
      int temp = min(c[u], res);
      res -= temp;
      cnt -= temp;
      c[u] -= temp;
    }
    if (res > i - 1) {
      tot += res - i + 1;
      res = i - 1;
    }
  }
  return tot >= 2 * cnt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i <= m; i++) {
    int val, day;
    cin >> day >> val;
    num[day].push_back(val);
  }
  int ans = 0;
  int left = 1, right = 1e6;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (check(mid))
      ans = mid, right = mid - 1;
    else
      left = mid + 1;
  }
  cout << ans << endl;
}
