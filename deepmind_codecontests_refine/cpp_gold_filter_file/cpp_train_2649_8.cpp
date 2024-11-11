#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, i, a, time;
  cin >> n;
  cin >> x;
  int arr[n];
  time = 0;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  a = x;
  for (i = 0; i < n; i++) {
    time = time + (a * arr[i]);
    a = a - 1;
    if (a < 1) {
      a = 1;
    }
  }
  cout << time;
}
