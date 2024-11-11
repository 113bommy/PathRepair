#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, res = 0, max = 0;
  cin >> n;
  int arr_n[n];
  for (int i = 0; i < n; ++i) cin >> arr_n[i];
  cin >> m;
  int arr_m[m];
  for (int i = 0; i < m; ++i) cin >> arr_m[i];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arr_m[i] % arr_n[j] == 0) {
        if (arr_m[i] / arr_n[j] == max)
          res++;
        else if (arr_m[i] / arr_n[j] > max) {
          max = arr_m[i] / arr_n[j];
          res = 1;
        }
        break;
      }
    }
  }
  cout << res;
  return 0;
}
