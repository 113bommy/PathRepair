#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, k;
  cin >> m >> n >> k;
  int arr[1005];
  memset(arr, 255, sizeof(arr));
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    if (arr[a] == -1)
      arr[a] = b;
    else
      arr[a] = min(arr[a], b);
  }
  int res = 0;
  for (int i = 0; i < n; i++)
    if (arr[i] >= 0) res += arr[i];
  cout << min(res, k) << endl;
}
