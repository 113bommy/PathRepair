#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int arr[110];
  int one = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] == 1) one++;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int cnt = one;
      for (int k = i; k <= j; k++) {
        int tem = 1 - arr[k];
        if (tem == 1)
          cnt++;
        else
          cnt--;
      }
      res = max(res, cnt);
    }
  }
  cout << res << endl;
  return 0;
}
