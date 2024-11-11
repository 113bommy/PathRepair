#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, i;
  long long x, y, z;
  cin >> n >> m;
  long long arr[n];
  for (i = 1; i < n + 1; i++) arr[i] = 0;
  for (i = 0; i < m; i++) {
    cin >> x >> y >> z;
    if (arr[x] == 0 && arr[y] == 0 && arr[z] == 0) {
      arr[x] = 1;
      arr[y] = 2;
      arr[z] = 3;
    }
    if (arr[x] == 1) {
      arr[y] = 2;
      arr[z] = 3;
    } else if (arr[x] == 2) {
      arr[y] = 1;
      arr[z] = 3;
    } else if (arr[x] == 3) {
      arr[y] = 2;
      arr[z] = 1;
    } else if (arr[y] == 1) {
      arr[x] = 2;
      arr[z] = 3;
    } else if (arr[y] == 2) {
      arr[x] = 1;
      arr[z] = 3;
    } else if (arr[y] == 3) {
      arr[x] = 2;
      arr[z] = 1;
    } else if (arr[z] == 1) {
      arr[y] = 2;
      arr[x] = 3;
    } else if (arr[z] == 2) {
      arr[y] = 1;
      arr[x] = 3;
    } else {
      arr[y] = 2;
      arr[x] = 1;
    }
  }
  for (i = 1; i < n + 1; i++) cout << arr[i] << " ";
  return 0;
}
