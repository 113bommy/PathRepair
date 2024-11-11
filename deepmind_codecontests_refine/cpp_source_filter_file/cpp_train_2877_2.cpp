#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, ans, tmp, t, curr, x, r, sm, k, l;
long long arr[1000005], res[1000005], par1[1000005], par2[1000005];
string s;
vector<long long> vec[1000005];
void dfs(long long idx, long long par, long long col) {
  if (col != arr[idx]) {
    ans++;
    col = arr[idx];
  }
  for (long long i = 0; i < vec[idx].size(); i++) {
    if (vec[idx][i] == par) continue;
    dfs(vec[idx][i], idx, col);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (i = 2; i <= n; i++) {
    cin >> x;
    vec[x].push_back(i + 1);
  }
  for (i = 1; i <= n; i++) cin >> arr[i];
  dfs(1, -1, 0);
  cout << ans << "\n";
  return 0;
}
