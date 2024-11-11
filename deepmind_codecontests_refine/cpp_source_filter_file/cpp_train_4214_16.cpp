#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, arr[4], arr2[4], k;
  cin >> n;
  int flag = 0;
  double avg, med;
  for (i = 0; i < n; i++) cin >> arr[i];
  if (n == 4) {
    sort(arr, arr + 4);
    avg = (arr[0] + arr[1] + arr[2] + arr[3]) / 4.0;
    med = (arr[1] + arr[2]) / 2.0;
    if (avg == med && (double)(arr[3] - arr[0]) == avg) {
      cout << "YES";
    } else
      cout << "NO";
  } else if (n == 3) {
    for (i = 1; i <= 500; i++) {
      for (k = 0; k < 4; k++) arr2[k] = arr[k];
      arr2[3] = i;
      sort(arr2, arr2 + 4);
      avg = (double)(arr2[0] + arr2[1] + arr2[2] + arr2[3]) / 4.0;
      med = (double)(arr2[1] + arr2[2]) / 2.0;
      if (avg == med && (double)(arr2[3] - arr2[0]) == avg) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << "YES" << endl << i;
    } else
      cout << "NO";
  } else if (n == 2) {
    for (i = 1; i <= 500; i++) {
      for (j = 1; j <= 500; j++) {
        for (k = 0; k < 4; k++) arr2[k] = arr[k];
        arr2[2] = i;
        arr2[3] = j;
        sort(arr2, arr2 + 4);
        avg = (arr2[0] + arr2[1] + arr2[2] + arr2[3]) / 4.0;
        med = (arr2[1] + arr2[2]) / 2.0;
        if (avg == med && (double)(arr2[3] - arr2[0]) == avg) {
          flag = 1;
          break;
        }
      }
      if (flag) {
        break;
      }
    }
    if (flag) {
      cout << "YES" << endl << i << endl << j;
    } else
      cout << "NO";
  } else if (n == 1) {
    n = arr[0];
    cout << "YES" << endl << n << endl << 3 * n << endl << 3 * n << endl;
  } else if (n == 0) {
    cout << "YES" << endl << 1 << endl << 1 << endl << 3 << endl << 3 << endl;
  }
  return 0;
}
