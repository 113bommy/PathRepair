#include <bits/stdc++.h>
const int MX = 100005;
using namespace std;
int main() {
  int m;
  cin >> m;
  int ar[m + 5];
  for (int i = 0; i < m; i++) {
    cin >> ar[i];
  }
  int x, y;
  cin >> x >> y;
  for (int i = 1; i < m; i++) {
    ar[i] += ar[i - 1];
  }
  int ans = 0;
  for (int i = 1; i < m; i++) {
    int g1 = ar[i - 1];
    int g2 = ar[m - 1] - ar[i - 1];
    if (g1 >= x && g1 <= y && g2 >= x && g2 <= y) {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
