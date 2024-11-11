#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  int b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  for (int i = 0; i < m; i++) {
    int low = 0;
    int high = n - 1;
    int count = 0;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (a[mid] <= b[i]) {
        count += mid - low + 1;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    cout << count << " ";
  }
}
