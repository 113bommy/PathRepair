#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int max_n = INT_MIN, min_n = INT_MAX;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > max_n)
      max_n = a[i];
    else if (a[i] < min_n)
      min_n = a[i];
  }
  if (n == 1 || max_n == min_n) {
    cout << 0 << endl;
    return 0;
  }
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (max_n - a[i]);
  }
  cout << sum << endl;
  return 0;
}
