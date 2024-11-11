#include <bits/stdc++.h>
using namespace std;
int ara[110][110];
int main() {
  int n, k;
  cin >> n >> k;
  if (k > n * n) {
    cout << -1 << endl;
    return 0;
  }
  int a = k;
  for (int i = 1; i <= n; i++) {
    if (k > 0) {
      ara[i][i] = 1;
      k--;
    }
    for (int j = i + 1; j <= n; j++) {
      if (k > 1) {
        ara[i][j] = 1;
        ara[j][i] = 1;
        k -= 2;
      }
    }
  }
  if (k > 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << ara[i][j] << ' ';
    cout << endl;
  }
}
