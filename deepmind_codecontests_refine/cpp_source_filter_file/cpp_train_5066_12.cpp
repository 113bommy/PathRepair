#include <bits/stdc++.h>
using namespace std;
int search(long long int a[], long long int x, int n) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] >= x) {
      if (a[mid - 1] < x)
        return mid - 1;
      else
        high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  long long int r[n], q[m], a[m];
  for (int i = 0; i < n; i++) cin >> r[i];
  for (int i = 0; i < m; i++) cin >> q[i];
  a[0] = r[0];
  for (int i = 1; i < n; i++) a[i] = (a[i - 1] + r[i]);
  for (int i = 0; i < m; i++) {
    if (a[0] >= q[i])
      cout << 1 << " " << q[i] << endl;
    else {
      int ret;
      ret = search(a, q[i], n);
      cout << ret + 2 << " " << q[i] - a[ret] << endl;
    }
  }
  return 0;
}
