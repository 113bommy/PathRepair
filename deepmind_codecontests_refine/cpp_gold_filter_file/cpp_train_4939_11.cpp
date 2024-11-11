#include <bits/stdc++.h>
using namespace std;
int arr[110][110];
int main() {
  int n, m, cnt;
  while (cin >> n >> m >> cnt) {
    int sum, temp, res;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> arr[i][j];
      }
    }
    res = 0x3f3f3f3f;
    if (n > cnt) {
      for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = 0; j < n; ++j) {
          temp = 0;
          for (int k = 0; k < m; ++k) {
            temp += arr[i][k] ^ arr[j][k];
          }
          sum += min(m - temp, temp);
        }
        res = min(res, sum);
      }
    } else {
      for (int i = 0; i < (1 << n); ++i) {
        sum = 0;
        for (int j = 0; j < m; ++j) {
          temp = 0;
          for (int k = 0; k < n; ++k) {
            temp += arr[k][j] ^ ((i >> k) & 1);
          }
          sum += min(n - temp, temp);
        }
        res = min(res, sum);
      }
    }
    cout << (res > cnt ? -1 : res) << endl;
  }
  return 0;
}
