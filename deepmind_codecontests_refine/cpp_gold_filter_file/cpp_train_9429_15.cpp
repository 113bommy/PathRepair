#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (long long i = 0; i < n - 2; i++) {
    if (arr[i] + arr[i + 1] > arr[i + 2] && arr[i + 2] + arr[i + 1] > arr[i] &&
        arr[i] + arr[i + 2] > arr[i + 1]) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
