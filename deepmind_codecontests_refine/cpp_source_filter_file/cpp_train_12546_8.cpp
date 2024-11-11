#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long j = 0;
  long long sum = 0;
  long long maxm = 100000000000;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    sum = sum + arr[i];
    if (arr[i] % 2 != 0 && arr[i] < maxm) {
      maxm = sum;
    }
  }
  if (sum % 2 == 0) {
    cout << sum;
    return 0;
  } else {
    cout << sum - maxm;
  }
  return 0;
}
