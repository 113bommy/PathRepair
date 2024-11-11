#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    for (int j = w; j <= y; j++) {
      for (int k = x; k <= z; k++) {
        a[j][k]++;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 105; i++) {
    for (int j = 0; j < 105; j++) {
      ans += a[i][j];
    }
  }
  cout << ans << endl;
}
