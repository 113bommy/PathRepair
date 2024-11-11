#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e4, M = 1e9 + 7;
map<int, int> m2;
int a[101][101];
int main() {
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  if (k > n * n) {
    cout << -1;
    return 0;
  }
  if (n == 1) {
    if (k == 0) {
      cout << 0;
      return 0;
    }
    cout << 1;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (k == 0) {
      break;
    }
    k -= 1;
    a[i][i] = 1;
    for (int j = i + 1; j < n; j++) {
      if (k > 1) {
        k -= 2;
        a[i][j] = 1;
        a[j][i] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << a[i][j] << " ";
    cout << endl;
  }
}
