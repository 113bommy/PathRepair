#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v, i, j, k, cnt = 0;
  cin >> n >> v;
  int b[n];
  for (i = 1; i <= n; i++) {
    cin >> k;
    int a[k];
    for (j = 0; j < k; j++) cin >> a[j];
    for (j = 0; j < n; j++) {
      if (v > a[j]) {
        b[cnt] = i;
        cnt++;
        break;
      }
    }
  }
  cout << cnt << endl;
  for (j = 0; j < cnt; j++) {
    cout << b[j] << " ";
  }
}
