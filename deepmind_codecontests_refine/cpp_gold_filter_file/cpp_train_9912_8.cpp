#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, s;
    cin >> n >> s;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    long long int sum = 0, ans = 0;
    for (long long int i = 0; i < n; i++) {
      sum += arr[i];
      if (sum > s) {
        int j = 0, max = arr[i];
        ans = i + 1;
        while (j <= i) {
          if (arr[j] > max) {
            max = arr[j];
            ans = j + 1;
          }
          j++;
        }
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
