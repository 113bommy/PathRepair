#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int xy[n][2];
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < 2; i++) {
      cin >> xy[j][i];
    }
  }
  int s = 0;
  for (int i = 0; i < n - 2; i++) {
    if (xy[i][1] < xy[i + 1][1] && xy[i + 1][0] > xy[i + 2][0]) {
      s++;
    } else if (xy[i][1] > xy[i + 1][1] && xy[i + 1][0] < xy[i + 2][0]) {
      s++;
    } else if (xy[i][0] < xy[i + 1][0] && xy[i + 1][1] < xy[i + 2][1]) {
      s++;
    } else if (xy[i][0] > xy[i + 1][0] && xy[i + 1][1] > xy[i + 2][1]) {
      s++;
    }
  }
  cout << s;
  return 0;
}
