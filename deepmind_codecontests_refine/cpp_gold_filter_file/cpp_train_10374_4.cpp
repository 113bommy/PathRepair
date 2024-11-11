#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[100010];
  for (int i = 0; i < n; i++) cin >> a[i];
  int b[100010];
  int min_ind = n;
  int min = INT_MAX;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] < min) {
      min_ind = i;
      min = a[i];
    }
    b[i] = min_ind;
  }
  int c[100010];
  for (int i = 0; i < n; i++) {
    int l = i;
    int k = n - 1;
    c[i] = i;
    while (l < k) {
      int mid = l + ((k - l) + 1) / 2;
      if (a[b[mid]] < a[i]) {
        c[i] = b[mid];
        l = mid;
      } else
        k = mid - 1;
    }
  }
  for (int i = 0; i < n; i++) cout << c[i] - i - 1 << " ";
  cout << '\n';
  return 0;
}
