#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 1e17;
long long int a[1000001] = {0};
int main() {
  ios_base::sync_with_stdio(0);
  long long int n, m, i, j, k, l, x, y;
  cin >> n >> m >> k;
  long long int b[m];
  for (i = 0; i < m; i++) {
    cin >> b[i];
    a[b[i]] = 1;
  }
  long long int ans = 1, flag = 0;
  if (a[1] == 1) {
    flag = 1;
  }
  for (i = 0; i < k; i++) {
    cin >> x >> y;
    if (ans == x) {
      if (flag == 0) {
        ans = y;
      }
      if (a[y] == 1 && flag == 0) {
        flag = 1;
      }
    } else if (ans == y) {
      if (flag == 0) {
        ans = x;
      }
      if (a[x] == 1 && flag == 0) {
        flag = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
