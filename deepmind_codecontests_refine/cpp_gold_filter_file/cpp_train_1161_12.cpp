#include <bits/stdc++.h>
using namespace std;
long long n;
long long sum[200003];
vector<int> dian[200003];
long long ans = 1;
int dfs(int cur, int pre) {
  ans *= sum[dian[cur].size()];
  for (auto i : dian[cur]) {
    ans %= 998244353;
    if (i != pre) dfs(i, cur);
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  sum[0] = 1;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] * i % 998244353;
  long long y, x;
  for (int i = 1; i < n; i++)
    cin >> x >> y, dian[x].push_back(y), dian[y].push_back(x);
  dfs(1, 0);
  cout << (ans * n) % 998244353;
  return 0;
}
