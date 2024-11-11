#include <bits/stdc++.h>
using namespace std;
long long a[100];
long long sum[100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, n, k, j = 1;
  cin >> n >> k;
  a[1] = sum[1] = 1;
  for (i = 2; i <= 50; i++) {
    if (sum[i - 1] - sum[max(i - k - 1, 0)] > n) break;
    j++;
    a[i] = sum[i - 1] - sum[max(i - k - 1, 0)];
    sum[i] = sum[i - 1] + a[i];
  }
  vector<int> ans;
  for (i = j; i >= 0; i--) {
    if (n >= a[i]) {
      n -= a[i];
      ans.push_back(a[i]);
    }
    if (!a[i]) break;
  }
  cout << ans.size() << "\n";
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
