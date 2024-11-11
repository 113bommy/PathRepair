#include <bits/stdc++.h>
using namespace std;
int arr[105][105];
int brr[105];
int main() {
  int n, i, j, val, cnt = 0;
  cin >> n;
  memset(brr, 1, sizeof brr);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cin >> val;
      if (val == 3) {
        brr[i] = 0;
        brr[j] = 0;
      } else if (val == 2)
        brr[j] = 0;
      else if (val == 1)
        brr[i] = 0;
    }
  }
  for (i = 1; i <= n; i++)
    if (brr[1]) cnt++;
  cout << cnt << endl;
  for (i = 1; i <= n; i++)
    if (brr[i]) cout << i << " ";
  cout << endl;
  return 0;
}
