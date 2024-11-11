#include <bits/stdc++.h>
using namespace std;
int a[10001];
bool possible(int n, int k, double p) {
  int i;
  double positive = 0, negative = 0;
  for (i = 0; i < n; i++) {
    if ((double)a[i] < p)
      negative = negative + p - (double)a[i];
    else
      positive = positive + (double)a[i] - p;
  }
  if (negative <= ((double)(100 - k) / 100) * positive)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, i, s = 0;
  double rez, p = 0, br;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  for (br = (double)s / 2; br >= 0.00000001; br = br / 2) {
    while (possible(n, k, p + br) == true && p + br < (double)s) p += br;
  }
  printf("%.8f", p);
  return 0;
}
