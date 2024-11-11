#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int arr[3] = {0};
  arr[0] = (k * l) / nl;
  arr[1] = c * d;
  arr[2] = p / np;
  sort(arr, arr + 3);
  cout << arr[0] / n << endl;
  return 0;
}
