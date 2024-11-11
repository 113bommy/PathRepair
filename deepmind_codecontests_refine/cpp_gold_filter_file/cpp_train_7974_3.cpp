#include <bits/stdc++.h>
using namespace std;
long long sum(long long n) { return (1ll << n) - 1; }
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m) {
    int arr[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> arr[i][j];
    long long res = 0;
    for (int i = 0; i < n; i++) {
      long long o = 0, z = 0;
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == 1) o++;
        if (arr[i][j] == 0) z++;
      }
      if (o) res += sum(o);
      if (z) res += sum(z);
    }
    for (int j = 0; j < m; j++) {
      long long o = 0, z = 0;
      for (int i = 0; i < n; i++) {
        if (arr[i][j] == 1) o++;
        if (arr[i][j] == 0) z++;
      }
      if (o) res += sum(o) - o;
      if (z) res += sum(z) - z;
    }
    cout << res << endl;
  }
  return 0;
}
