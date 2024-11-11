#include <bits/stdc++.h>
using namespace std;
long long mod(long long a) { return a > 0 ? a : -a; }
int main() {
  long long n, i, ii, d, cou, ans, j;
  bool flag = true;
  cin >> n;
  long long arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  if (n == 1)
    cout << "-1" << endl;
  else if (n == 2) {
    if (arr[0] == arr[1])
      cout << "1" << endl << arr[0] << endl;
    else if (mod(arr[1] - arr[0]) % 2 == 0)
      cout << "3" << endl
           << 2 * arr[0] - arr[1] << " " << arr[0] + ((arr[1] - arr[0]) / 2)
           << " " << 2 * arr[1] - arr[0] << endl;
    else
      cout << "2" << endl
           << 2 * arr[0] - arr[1] << " " << 2 * arr[1] - arr[0] << endl;
  } else {
    if (((arr[n - 1] - arr[0]) % (n - 1)) == 0) {
      d = (arr[n - 1] - arr[0]) / (n - 1);
      for (i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1] + d) {
          flag = false;
          break;
        }
      }
      if (flag) {
        if (arr[0] == arr[1])
          cout << "1" << endl << arr[0] << endl;
        else
          cout << "2" << endl << arr[0] - d << " " << arr[n - 1] + d << endl;
        goto last;
      }
    }
    flag = true;
    cou = 0;
    ans = 0;
    d = (arr[n - 1] - arr[0]) / n;
    j = 1;
    for (i = 1; i < n; j++) {
      if (arr[i] != arr[0] + j * d) {
        ans = arr[0] + j * d;
        if (cou == 1) {
          flag = false;
          break;
        }
        cou++;
      } else
        i++;
    }
    if (flag) {
      cout << "1" << endl << ans << endl;
      goto last;
    }
    cout << "0" << endl;
  last:
    cout << "";
  }
}
