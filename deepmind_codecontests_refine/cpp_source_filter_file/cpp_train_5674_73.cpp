#include <bits/stdc++.h>
using namespace std;
int e[101][101];
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> e[i][j];
    }
  }
  int win[n];
  for (int i = 1; i < n; i++) {
    win[i] = 0;
  }
  int max, index;
  for (int i = 0; i < m; i++) {
    max = e[i][0];
    index = 0;
    for (int j = 1; j < n; j++) {
      if (e[i][j] > max) {
        max = e[i][j];
        index = j;
      }
    }
    win[index + 1]++;
  }
  int max2 = win[1];
  int ans = 1;
  for (int i = 2; i < n; i++) {
    if (win[i] > max2) {
      max2 = win[i];
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
