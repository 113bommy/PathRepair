#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, arr[100], min1 = 1500, p = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + m);
  for (int i = 0; i <= m - n + 1; i++) {
    p = abs(arr[i + n - 1] - arr[i]);
    min1 = min(min1, p);
  }
  cout << min1;
  return 0;
}
