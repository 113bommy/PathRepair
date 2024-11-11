#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int n;
int a[1001][6];
int b[1001][1001][6];
bool test(int i) {
  for (int i1 = 1; i1 <= n; i1++)
    for (int i2 = 1; i2 <= n; i2++)
      if (i != i1 and i != i2 and i1 != i2) {
        int s = 0;
        for (int k = 1; k <= 5; k++) s += b[i][i1][k] * b[i][i2][k];
        if (s > 0) return 0;
      }
  return 1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 5; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        for (int k = 1; k <= 5; k++) b[i][j][k] = a[j][k] - a[i][k];
      }
    }
  for (int i = 1; i <= n; i++)
    if (test(i)) ans.push_back(i);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return 0;
}
