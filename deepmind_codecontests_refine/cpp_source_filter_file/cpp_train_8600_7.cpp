#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    int arr[16];
    memset(arr, -1, sizeof(arr));
    int ss[3] = {4, 6, 9};
    arr[0] = 0;
    for (int i = 1; i <= 15; i++)
      for (int j = 0; j < 3; j++) {
        if (i < ss[j] || arr[i - ss[j]] == -1) continue;
        arr[i] = max(arr[i], arr[i - ss[j]] + 1);
      }
    if (a <= 15) {
      cout << arr[a] << endl;
      continue;
      ;
    }
    cout << ((a - 16) / 4 + 1 + arr[a - ((a - 16) / 4 + 1)]) << endl;
  }
  return 0;
}
