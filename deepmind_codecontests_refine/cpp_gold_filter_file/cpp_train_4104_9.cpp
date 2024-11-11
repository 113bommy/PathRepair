#include <bits/stdc++.h>
using namespace std;
int n, b[5010];
long long tr[5010];
int gx1[5010][5010], gx2[5010][5010];
inline int lowbit(int x) { return (x & (-x)); }
void xg(int x, int k) {
  for (int i = x; i <= n + 1; i += lowbit(i)) {
    tr[i] += k;
  }
}
long long getsum(int x) {
  long long res = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    res += tr[i];
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i]++;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      gx1[i][j] = getsum(n + 1) - getsum(b[j]);
    }
    xg(b[i], 1);
    ans += getsum(n + 1) - getsum(b[i]);
  }
  memset(tr, 0, sizeof(tr));
  for (int i = n; i > 0; i--) {
    for (int j = 1; j <= n; j++) {
      gx2[i][j] = getsum(b[j] - 1);
    }
    xg(b[i], 1);
  }
  if (ans == 0) {
    cout << "0 0";
    return 0;
  }
  int maxx = 999999999, tt = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int tot = ans + (gx1[i][j] - gx1[j][j] + gx2[i][j] - gx2[j][j]) +
                (gx2[j][i] - gx2[i][i] + gx1[j][i] - gx1[i][i]);
      if (b[i] > b[j]) tot++;
      if (maxx == tot) tt++;
      if (maxx > tot) maxx = tot, tt = 1;
    }
  }
  cout << maxx << " " << tt;
  return 0;
}
