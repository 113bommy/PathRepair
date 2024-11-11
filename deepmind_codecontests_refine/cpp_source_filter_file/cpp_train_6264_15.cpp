#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 0;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    m = max(arr[i], m);
  }
  int i = 0;
  if (m != arr[0]) {
    for (i = 1; arr[i + 1] != m; i++) {
      if (arr[i] >= arr[i + 1]) {
        cout << "NO";
        return 0;
      }
    }
    i++;
  }
  for (; i < n - 1; i++) {
    if (arr[i] <= arr[i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
