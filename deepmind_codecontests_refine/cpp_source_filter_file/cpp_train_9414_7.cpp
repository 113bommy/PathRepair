#include <bits/stdc++.h>
const clock_t tl = 0.9 * CLOCKS_PER_SEC;
double start;
long long p = 307, mod = 99999989;
#pragma comment(linker, "/STACK:25600000")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  map<int, int> d, bad, b;
  int a;
  int arr[1000][1000];
  for (int i = 1; i <= n; i++) {
    d.clear();
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    d.clear();
    for (int j = 1; j <= m; j++) {
      a = arr[j][i];
      if (a == 0) continue;
      if (bad[j]) {
        continue;
      }
      if (b[a]) {
        bad[j] = i;
      }
      if (d[a]) {
        b[a] = 1;
        bad[d[a]] = i;
        bad[j] = i;
      }
      d[a] = j;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << bad[i] << '\n';
  }
  return 0;
}
