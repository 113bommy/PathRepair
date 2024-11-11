#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  int arr[n][2];
  int able = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0];
    cin >> arr[i][1];
    if (arr[i][0] < s)
      able++;
    else if (arr[i][0] == s && arr[i][1] == 0) {
      able++;
    }
  }
  if (able == 0)
    cout << "-1" << endl;
  else {
    int done = 0;
    for (int i = 0; i < n; i++) {
      int swab, swab2;
      for (int k = i + 1; k < n; k++) {
        if (arr[k][1] < arr[i][1]) {
          swab = arr[i][1];
          arr[i][1] = arr[k][1];
          arr[k][1] = swab;
          swab2 = arr[i][0];
          arr[i][0] = arr[k][0];
          arr[k][0] = swab2;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (arr[i][0] < s && arr[i][1] > 0) {
        cout << 100 - arr[i][1] << endl;
        done = 1;
        break;
      }
    }
    if (done == 0) cout << 0 << endl;
  }
  return 0;
}
