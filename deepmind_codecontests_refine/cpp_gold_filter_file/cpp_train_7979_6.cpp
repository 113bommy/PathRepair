#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n];
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    arr[a - 1]++;
  }
  int ans = m;
  for (int i = 0; i < n; i++) {
    ans = min(ans, arr[i]);
  }
  cout << ans;
}
