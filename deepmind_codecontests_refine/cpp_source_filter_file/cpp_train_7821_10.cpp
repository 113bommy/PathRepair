#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long count = 0;
  count = arr[n - 1];
  long long temp = arr[n - 1];
  for (long long i = n - 2; i >= 0; i--) {
    if (temp > 0) {
      if (arr[i] < temp) {
        temp = arr[i];
        count += arr[i];
      } else if (arr[i] == temp) {
        temp = arr[i] - 1;
        count += (arr[i] - 1);
      } else {
        count += (temp - 1);
        arr[i] = temp - 1;
      }
    }
  }
  cout << count;
}
