#include <bits/stdc++.h>
using namespace std;
int arr[100009];
int main() {
  int n, m, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> m;
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    int l = 0, r = n;
    while (l + 1 != r) {
      int mi = (l + r) / 2;
      if (arr[mi] - arr[i] <= m)
        l = mi;
      else
        r = mi;
    }
    ans = max(ans, l - i + 1);
  }
  cout << ans << '\n';
}
