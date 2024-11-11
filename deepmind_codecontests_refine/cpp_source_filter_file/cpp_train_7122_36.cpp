#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int m, n, ans = 0;
  int arr[100000];
  cin >> n >> m;
  memset(arr, 0, 100000);
  for (; m--;) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a] -= c;
    arr[b] += c;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] > 0) {
      ans += arr[i];
    }
  }
  cout << ans << endl;
  return (0);
}
