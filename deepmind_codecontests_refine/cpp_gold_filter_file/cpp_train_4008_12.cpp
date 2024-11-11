#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w;
  cin >> n >> w;
  int a[2 * n];
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  sort(a, a + 2 * n);
  double girls = (double)a[0];
  double boys, x;
  int temp = 1;
  while ((double)a[temp] < 2 * girls && temp < 2 * n) temp++;
  if (temp > n) {
    boys = (double)a[n];
    girls = boys / 2;
    x = girls;
  } else {
    boys = 2 * girls;
    x = girls;
  }
  double wx = (double)((double)w / (double)n);
  wx = wx / 3;
  if (x > wx) x = wx;
  double total = 3 * (double)n * x;
  cout << fixed << setprecision(6) << total;
}
