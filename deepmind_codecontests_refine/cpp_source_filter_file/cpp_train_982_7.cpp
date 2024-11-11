#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e3;
const int M = 1e4;
int a[N][N];
int main() {
  int n, k, d;
  cin >> n >> k >> d;
  int flag = 1;
  memset((a), (0), sizeof(a));
  if (n == 1) {
    while (d--) cout << 1 << endl;
    return 0;
  }
  for (int i = 1; i <= d; i++) a[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= d; j++) a[i][j] = a[i - 1][j];
    a[i][d]++;
    for (int j = d; j > 0; j--) {
      if (a[i][d] > k)
        a[i][d] = 1, a[i][d - 1]++;
      else
        break;
    }
    if (a[i][0] == 1) {
      flag = 0;
      break;
    }
  }
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }
  for (int j = 1; j <= d; j++) {
    for (int i = 1; i <= n; i++) {
      if (i > 1) cout << ' ';
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
