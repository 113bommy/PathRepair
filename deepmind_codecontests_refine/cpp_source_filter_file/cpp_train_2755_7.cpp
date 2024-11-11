#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int minn = INT_MAX;
  for (int i = 1; i < n - 1; i++) {
    int maxx = INT_MIN;
    for (int j = 1; j < n - 1; j++) {
      if (i == j) {
        maxx = max(maxx, arr[i + 1] - arr[i - 1]);
        j++;
      } else {
        maxx = max(maxx, arr[j] - arr[j - 1]);
      }
    }
    minn = min(maxx, minn);
  }
  cout << minn;
  return 0;
}
