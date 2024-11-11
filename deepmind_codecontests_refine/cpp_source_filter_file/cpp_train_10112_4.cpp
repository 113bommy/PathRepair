#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int main() {
  int n, m, i, j, sum = 0;
  memset(b, 0, sizeof(b));
  cin >> n >> m;
  for (i = 0; i < m; i++) cin >> a[i];
  for (i = 0; i < m; i++) {
    b[a[i]]++;
    if (b[a[i]] == 1) sum++;
    if (sum == n) {
      cout << "1";
      for (j = 0; j < n; j++) {
        b[j]--;
        if (b[j] == 0) sum--;
      }
    } else
      cout << "0";
  }
  return 0;
}
