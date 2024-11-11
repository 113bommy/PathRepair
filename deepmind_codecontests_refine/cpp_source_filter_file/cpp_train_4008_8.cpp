#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double w;
  cin >> n >> w;
  int a[2000000];
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a, a + 2 * n);
  double min_g = (double)a[0];
  double min_b = (double)a[n];
  double total;
  if ((min_b / 2) > min_g) {
    total = min_g * 3 * n;
  } else {
    total = (min_b / 2) * 3 * n;
  }
  total = min(total, w);
  cout << setprecision(6) << total;
  return 0;
}
