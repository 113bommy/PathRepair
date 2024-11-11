#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long ans = 0;
  for (long long i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      long long j = i;
      long long cnt = 0;
      while (j < n && arr[j] == arr[i]) {
        cnt++;
        j++;
      }
      i = j - 1;
      ans += (cnt * (cnt - 1)) / 2;
    }
  }
  cout << ans + n;
}
