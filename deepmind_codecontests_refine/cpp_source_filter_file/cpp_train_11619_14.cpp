#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  int l, r, x;
  for (i = 0; i < m; i++) {
    cin >> l >> r >> x;
    l--, r--, x--;
    int cnt = 0;
    for (j = l; j <= r; j++) {
      if (arr[j] < arr[x]) cnt++;
    }
    if ((l + cnt) == x)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
