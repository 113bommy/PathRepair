#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a[4]) {
  long long int m = a[0];
  for (int i = 1; i < 4; i++) {
    if (a[i] < m) m = a[i];
  }
  return m;
}
int main() {
  long long int d1, d2, d3, arr[4];
  cin >> d1 >> d2 >> d3;
  arr[0] = 2 * d1 + 2 * d2;
  arr[1] = d1 + d2 + d3;
  arr[2] = 2 * d1 + 2 * d3;
  arr[3] = 2 * d2 + 2 * d3;
  cout << min(arr) << '\n';
}
