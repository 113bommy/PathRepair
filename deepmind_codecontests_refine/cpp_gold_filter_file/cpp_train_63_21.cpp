#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  int c = 1;
  for (int i = 0; i <= n - 1; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = n - 1; i >= 0; --i) {
    if (k % arr[i] == 0) {
      cout << k / arr[i] << "\n";
      break;
    }
  }
}
