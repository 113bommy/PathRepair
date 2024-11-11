#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> arr(n + 1);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long minute;
  long long mn = 100000000000;
  long long ans = 0;
  long long x;
  for (long long i = 0; i < n; i++) {
    x = arr[i];
    if ((x - i) <= 0)
      minute = i;
    else {
      minute = n * ceil((x - i) / (double)n);
      minute += i;
    }
    if (minute < mn) {
      mn = minute;
      ans = i;
    }
  }
  cout << ans + 1;
  return 0;
}
