#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(arr.rbegin(), arr.rend());
  vector<int> ans(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ans[a]++;
    ans[b + 1]--;
  }
  for (int i = 1; i < n; ++i) {
    ans[i] += ans[i - 1];
  }
  sort(ans.rbegin(), ans.rend());
  int64_t counts = 0;
  for (int i = 0; i < n; ++i) {
    counts += ans[i] * arr[i];
  }
  cout << counts;
  return 0;
}
