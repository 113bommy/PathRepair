#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 19;
int vis[N], A[N];
pair<int, int> num[N];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    num[i] = pair<int, int>(A[i], i);
  }
  sort(num + 1, num + 1 + n);
  int res = n - m * k;
  for (int i = 1; i <= n; ++i) vis[i] = 1;
  for (int i = 1; i <= res; ++i) vis[num[i].second] = 0;
  int sum = 0;
  int p = (n - res) / k;
  long long asum = 0;
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    sum += vis[i];
    asum += 1ll * vis[i] * A[i];
    if (sum == p) {
      --k;
      sum = 0;
      ans.push_back(i);
      if (k == 1) p = 1e9 + 7;
    }
  }
  cout << asum << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
  return 0;
}
