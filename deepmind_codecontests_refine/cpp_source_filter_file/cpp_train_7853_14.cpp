#include <bits/stdc++.h>
using namespace std;
void NITRO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long arr[200009];
int main() {
  NITRO();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long ma = arr[n - 1] - arr[0], mi = arr[0], mm = arr[n - 1];
  cout << ma << " ";
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] != arr[i + 1]) {
      long long ki = 0, ul = 0;
      for (int o = 0; o < n; o++) {
        if (arr[o] == mi)
          ki++;
        else
          break;
      }
      for (int o = n - 1; o > 0; o--) {
        if (arr[o] == mm)
          ul++;
        else
          break;
      }
      cout << ul * ki;
      break;
    } else if (i == n - 2) {
      cout << n * (n - 1) / 2;
    }
  }
  return 0;
}
