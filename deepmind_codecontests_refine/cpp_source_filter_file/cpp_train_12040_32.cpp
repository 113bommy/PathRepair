#include <bits/stdc++.h>
using namespace std;
int g[1000001][15];
int cal(int m) {
  while (m >= 10) {
    int n = m;
    int sum = 1;
    while (n) {
      int temp = n % 10;
      n /= 10;
      if (temp) sum *= temp;
    }
    m = sum;
  }
  return m;
}
int main(void) {
  ios::sync_with_stdio(false);
  for (int i = 1; i <= 10; i++) {
    int cnt = 0;
    for (int j = 1; j <= 200001; j++) {
      if (cal(j) == i) {
        cnt++;
      }
      g[j][i] = cnt;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    int ans = g[r][k] - g[l][k];
    if (cal(l) == k) ans++;
    cout << ans << endl;
  }
}
