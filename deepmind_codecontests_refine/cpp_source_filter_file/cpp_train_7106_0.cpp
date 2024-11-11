#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[205], b[205];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 1; i < 512; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (((a[j] & b[k]) | i) == i) {
          cnt++;
          break;
        }
      }
    }
    if (cnt == n) {
      cout << i << endl;
      break;
    }
  }
}
