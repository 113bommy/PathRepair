#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int ts = 1;
  while (ts--) {
    int n, x1, x2, y1, y2;
    cin >> n;
    int a[101][101];
    for (int i = int(0); i < int(101); i++) {
      for (int j = int(0); j < int(101); j++) a[i][j] = 0;
    }
    for (int i = int(0); i < int(n); i++) {
      cin >> x1 >> y1;
      cin >> x2 >> y2;
      for (int j = int(x1); j < int(x2 + 1); j++) {
        a[j][y1]++;
        if (y2 + 1 <= 100) a[j][y2 + 1]--;
      }
    }
    int s = 0;
    for (int i = int(1); i < int(101); i++) {
      for (int j = int(1); j < int(101); j++) {
        a[i][j] += a[i][j - 1];
        if (a[i][j] > 0) s += a[i][j];
      }
    }
    cout << s << "\n";
  }
  return 0;
}
