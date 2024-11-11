#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  long long arr[n];
  int hours = 0;
  cin >> hours;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int ans = 0;
  for (int j = 0; j < n; j++) {
    ans = ans + arr[j] * max(hours - j, 1);
  }
  cout << ans << endl;
  return 0;
}
