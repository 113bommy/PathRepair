#include <bits/stdc++.h>
using namespace std;
int a[111][111], sum[111][111], n, m, k, maxi, mini;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++)
      if (a[i][j]) {
        int tmp = min(k, n - i + 1);
        int tempsum = 0;
        for (int pos = 0; pos < tmp; pos++) tempsum += a[pos + i][j];
        sum[i][j] = tempsum;
      }
  for (int j = 0; j < m; j++) {
    pair<int, int> tmp = {0, 0};
    for (int i = 0; i < n; i++) {
      if (sum[i][j] > tmp.first) tmp = {sum[i][j], i};
    }
    maxi += tmp.first;
    for (int i = 0; i < tmp.second; i++) mini += a[i][j];
  }
  cout << maxi << ' ' << mini << endl;
  return 0;
}
