#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long INF = 1e14;
int a[10], sum = 0;
int x[4], y[4], z[4];
int main() {
  for (int i = 0; i < 2; i++) cin >> x[i] >> y[i] >> z[i];
  for (int i = 0; i < 6; i++) cin >> a[i];
  if (y[0] < 0) sum += a[0];
  if (y[0] > y[1]) sum += a[1];
  if (z[0] < 0) sum += a[2];
  if (z[0] > z[1]) sum += a[3];
  if (x[0] < 0) sum += a[4];
  if (x[0] > x[1]) sum += a[5];
  cout << sum;
  return 0;
}
