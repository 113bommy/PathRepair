#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100001];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int sum[100001];
  sum[1] = a[1];
  for (int i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  int m;
  cin >> m;
  int b[100001];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    int l = 1;
    int r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (b[i] <= sum[1]) {
        cout << 1 << endl;
        break;
      }
      if (r - l == 1) {
        cout << r << endl;
        break;
      }
      if (sum[mid] < b[i]) {
        l = mid;
      } else if (sum[mid] > b[i]) {
        r = mid;
      } else {
        cout << mid << endl;
        break;
      }
    }
  }
}
