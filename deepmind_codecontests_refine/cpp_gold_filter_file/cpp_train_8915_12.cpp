#include <bits/stdc++.h>
using namespace std;
int n, a[200007], cnt = 0, ans = 0;
int dp[2][400007];
int bit[2][400007];
map<int, int> num;
vector<int> val;
void update(int type, int pos, int val) {
  for (int i = pos; i <= 2 * n; i += i & (-i)) {
    bit[type][i] = max(bit[type][i], val);
  }
}
int get(int type, int pos) {
  int ret = 0;
  for (int i = pos; i >= 1; i -= i & (-i)) {
    ret = max(ret, bit[type][i]);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] -= i;
    val.push_back(a[i]);
    val.push_back(a[i] + 1);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (int i = 0; i < (int)val.size(); i++) {
    num[val[i]] = i + 1;
  }
  for (int i = 1; i <= n; i++) {
    int id1 = num[a[i]];
    int id2 = num[a[i] + 1];
    dp[0][i] = max(dp[0][i], get(0, id1) + 1);
    dp[1][i] = max(dp[1][i], get(1, id2) + 1);
    if (i < n) {
      dp[1][i + 1] = max(dp[1][i + 1], get(0, num[a[i + 1] + 1]) + 1);
    }
    ans = max(ans, max(dp[0][i], dp[1][i]));
    update(0, id1, dp[0][i]);
    update(1, id2, dp[1][i]);
  }
  cout << max(0, n - ans - 1);
}
