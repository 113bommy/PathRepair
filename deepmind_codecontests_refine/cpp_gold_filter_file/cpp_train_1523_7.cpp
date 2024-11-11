#include <bits/stdc++.h>
using namespace std;
int n;
int d[5005][5005];
int x[5005], y[5005];
int b[5005];
int le, ri, mid;
int dfs(int x, int k) {
  if (b[x] >= 0) {
    return b[x] - k;
  }
  b[x] = k;
  for (int y = 0; y < n; y++) {
    if (d[x][y] > mid) {
      if (dfs(y, k ^ 1)) {
        return 1;
      }
    }
  }
  return 0;
}
int cal() {
  int ans = 1;
  memset(b, -1, sizeof(b));
  for (int i = 0; i < n; i++) {
    if (b[i] < 0) {
      if (dfs(i, 0)) {
        return -1;
      }
      ans = ans * 2 % 1000000007;
    }
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }
  }
  le = 0;
  ri = 1000000000;
  mid = (le + ri) / 2;
  while (ri > le) {
    mid = (le + ri) / 2;
    if (cal() == -1) {
      le = mid + 1;
    } else {
      ri = mid;
    }
  }
  mid = le;
  cout << mid << endl << cal();
  return 0;
}
