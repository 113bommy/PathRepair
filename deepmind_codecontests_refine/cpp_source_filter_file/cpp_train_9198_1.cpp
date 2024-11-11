#include <bits/stdc++.h>
using namespace std;
long long n, k, i, j, nums, cur;
vector<long long> ans[60000];
long long a[6000];
int main() {
  cin >> n >> cur;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; i++) {
    nums++;
    ans[nums].push_back(a[i]);
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j < n - i; j++) {
      nums++;
      ans[nums].push_back(a[j]);
      for (k = n - i; k <= n; k++) ans[nums].push_back(a[k]);
      if (nums > cur) break;
    }
  for (i = 1; i <= cur; i++) {
    cout << ans[i].size() << " ";
    for (j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
    cout << endl;
  }
}
