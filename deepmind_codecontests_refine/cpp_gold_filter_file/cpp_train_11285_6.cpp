#include <bits/stdc++.h>
using namespace std;
const int Mx = 1e5 + 5;
int arr[Mx];
int main() {
  int n, i, j;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (i = 30; i >= 0; i--) {
    int T = 1 << i;
    bool flag = false;
    for (j = n; j >= 1 && arr[j] >= T; j--)
      if (T & arr[j]) {
        flag = true;
        break;
      }
    if (flag) {
      int cnt = 0, tmp = (1 << 30) - 1;
      for (j; j >= 1 && arr[j] >= T; j--) {
        if (T & arr[j]) {
          tmp &= arr[j];
          cnt++;
        }
      }
      if (tmp % T != 0) continue;
      printf("%d\n", cnt);
      for (j = n; j >= 1 && arr[j] >= T; j--)
        if (T & arr[j]) printf("%d ", arr[j]);
      break;
    }
  }
  if (i < 0) puts("-1");
  return 0;
}
