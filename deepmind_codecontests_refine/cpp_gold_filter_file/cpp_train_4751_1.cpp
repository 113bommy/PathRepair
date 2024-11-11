#include <bits/stdc++.h>
using namespace std;
bool f[200005];
int main() {
  int n, i, m, k, l = 0, r = 0, c = 0, cur = 0;
  cin >> n >> m >> k;
  int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  if (k == 1)
    cout << n << "\n";
  else {
    cur = 1;
    while (r < n) {
      while ((arr[r] - arr[l] > m - 1 || f[l] == 1) && l < r) {
        if (f[l] == 0) cur--;
        l++;
      }
      if (cur == k && arr[r] - arr[l] <= m - 1) {
        f[r] = 1;
        c++;
        cur--;
      }
      r++;
      cur++;
    }
    cout << c << "\n";
  }
}
