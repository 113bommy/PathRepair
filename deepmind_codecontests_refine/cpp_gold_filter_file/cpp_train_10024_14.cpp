#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mini, maxi;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int min = 101, max = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      maxi = i + 1;
    }
    if (arr[i] <= min) {
      min = arr[i];
      mini = i + 1;
    }
  }
  int k = (maxi - 1) + (n - mini);
  if (mini < maxi) {
    cout << k - 1;
  } else
    cout << k;
  return 0;
}
