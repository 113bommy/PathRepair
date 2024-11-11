#include <bits/stdc++.h>
using namespace std;
int n, k, x, a[100010], c[100010], t, y, mem[505][5005], ans;
map<int, int> b;
int dp(int i = 1, int v = t) {
  if (v < 0) return -1e9;
  if (v == 0 || i == y + 1) return 0;
  int& ret = mem[i][v];
  if (~ret) return ret;
  ret = -1e9;
  for (int j = 0; j <= k; j++) {
    ret = max(ret, dp(i + 1, v - j) + c[j]);
  }
  return ret;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n * k; i++) {
    cin >> x;
    a[x]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    b[x]++;
  }
  for (int i = 1; i <= k; i++) cin >> c[i];
  for (auto p : b) {
    t = a[p.first];
    y = p.second;
    memset(mem, -1, sizeof mem);
    ans += dp();
  }
  cout << ans;
  return 0;
}
