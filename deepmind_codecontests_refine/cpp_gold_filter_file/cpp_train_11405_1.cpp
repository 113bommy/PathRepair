#include <bits/stdc++.h>
using namespace std;
int arr_c[101];
int arr_t[101];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int l, r, t, c;
    cin >> l >> r >> t >> c;
    for (int j = l; j <= r; ++j) {
      if (arr_t[j] == 0 || arr_t[j] > t) {
        arr_t[j] = t;
        arr_c[j] = c;
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += arr_c[i];
  }
  cout << sum;
  return 0;
}
