#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
const int drx[] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dry[] = {1, -1, 2, -2, 2, -2, 1, -1};
const int N = 400500;
int n, a[N], sum1, mx;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum1 += a[i];
    mx = max(mx, a[i]);
  }
  if (n == 1) {
    cout << mx * 2 + 1, exit(0);
  }
  for (int i = mx; i <= 100000; i++) {
    int sum2 = 0;
    for (int j = 1; j <= n; j++) {
      sum2 += max(0, i - a[j]);
    }
    if (sum2 > sum1) {
      cout << i, exit(0);
    }
  }
  return 0;
}
