#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[105][105];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cin >> arr[i][j];
  }
  if (n == 1)
    cout << "0";
  else {
    bool visit[105][105] = {false};
    vector<int> ans(105);
    for (int i = 0; i < ans.size(); i++) ans[i] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        if (visit[i][j] == false) {
          visit[i][j] = true, visit[j][i] = true;
          ans[i] |= arr[i][j];
          ans[j] |= arr[i][j];
        }
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  }
  return 0;
}
