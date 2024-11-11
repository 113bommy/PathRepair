#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, i, j, m, k;
  cin >> n >> m >> k;
  int arr[n + 1][m + 1];
  vector<int> vec(m + 1, 0);
  for (i = 1; i < n + 1; ++i) {
    for (j = 1; j < m + 1; ++j) {
      cin >> arr[i][j];
    }
  }
  vector<int> ans(m + 1, 0);
  while (k--) {
    cin >> i >> j;
    ans[i]--;
    vec[j]++;
  }
  for (i = 1; i < n + 1; ++i) {
    for (j = 1; j < m + 1; ++j) {
      if (arr[i][j] == 1) ans[i] += vec[j];
    }
    cout << ans[i] << " ";
  }
}
