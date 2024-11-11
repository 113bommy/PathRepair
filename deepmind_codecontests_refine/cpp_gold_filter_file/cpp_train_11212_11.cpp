#include <bits/stdc++.h>
using namespace std;
map<int, int> map_;
int main() {
  int n;
  cin >> n;
  if (n < 2) {
    cout << "-1";
    return 0;
  }
  int a[15];
  int sum[15];
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    if (sum[n] - sum[i] != sum[i]) {
      cout << i;
      cout << "\n";
      for (int j = 1; j <= i; j++) {
        if (map_[j] != 1) {
          printf("%d ", j);
          map_[j] = 1;
        }
      }
      return 0;
    }
  }
  cout << "-1";
}
