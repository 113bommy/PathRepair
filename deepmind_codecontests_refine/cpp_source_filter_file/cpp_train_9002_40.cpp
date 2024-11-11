#include <bits/stdc++.h>
using namespace std;
int belongs(int n, int m, int r[102][4], int N) {
  int ans = 0;
  for (int i = 0; i < N; i++)
    if (r[i][0] <= n && r[i][1] <= m && r[i][2] >= n && r[i][3] >= m) {
      ans++;
    }
  return ans;
}
int main() {
  int n;
  cin >> n;
  int ans = 0;
  int r[102][4];
  for (int i = 0; i < n; i++) cin >> r[i][0] >> r[i][1] >> r[i][2] >> r[i][3];
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      ans += belongs(i, j, r, n);
    }
  cout << ans << endl;
}
