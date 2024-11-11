#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  const int maxN = n;
  int r[maxN];
  int c[maxN];
  int a[maxN][maxN];
  for (int i = 0; i < n; i++) {
    r[i] = 0;
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      r[i] = r[i] + a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    c[i] = 0;
    for (int j = 0; j < n; j++) {
      c[i] = c[i] + a[j][i];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (c[i] > r[i]) {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
