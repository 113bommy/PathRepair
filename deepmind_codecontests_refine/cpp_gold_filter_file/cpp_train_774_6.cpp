#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  cin >> m;
  int arr1[m];
  for (int j = 0; j < m; j++) cin >> arr1[j];
  sort(arr, arr + n);
  sort(arr1, arr1 + m);
  bool visited[n];
  bool visited1[m];
  for (int i = 0; i < n; i++) visited[i] = false;
  for (int i = 0; i < m; i++) visited1[i] = false;
  int ans, ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((abs(arr[i] - arr1[j]) <= 1) && visited1[j] == false) {
        ans1++;
        visited1[j] = true;
        break;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if ((abs(arr1[i] - arr[j]) <= 1) && visited[j] == false) {
        ans2++;
        visited[j] = true;
        break;
      }
    }
  }
  ans = max(ans2, ans1);
  cout << ans << "\n";
  return 0;
}
