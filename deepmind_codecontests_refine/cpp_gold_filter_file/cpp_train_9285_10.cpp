#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << arr[0] * arr[0];
  } else {
    sort(arr, arr + n, greater<int>());
    long long l = 0;
    long long h = 0;
    long long index;
    if (n % 2 == 0) {
      index = n / 2;
    } else {
      index = (n / 2) + 1;
    }
    for (long long i = 0; i < index; i++) {
      l += arr[i];
    }
    for (long long i = index; i < n; i++) {
      h += arr[i];
    }
    cout << (l * l) + (h * h);
  }
}
