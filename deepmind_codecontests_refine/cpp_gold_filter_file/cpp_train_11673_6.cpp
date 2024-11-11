#include <bits/stdc++.h>
using namespace std;
double c(int n, int r) {
  if (n == r || r == 0) return 1;
  double re = 1;
  if (r > n / 2) r = n - r;
  for (int i = 1, j = n; i <= r; i++, j--) {
    re *= j;
    re /= r;
  }
  return re;
}
int main(void) {
  int n, m, h;
  cin >> n >> m >> h;
  vector<int> v(m);
  int sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> v[i];
    sum += v[i];
  }
  v[h - 1]--;
  sum--;
  if (sum < n - 1)
    cout << "-1.0";
  else if (fabs(v[h - 1] - 0) < 1e-9)
    cout << "0.000000000";
  else if (sum == n - 1)
    cout << 1;
  else {
    double re = 1.0;
    n--;
    int p = n;
    for (int i = 1; i <= p; i++) {
      if (sum - v[h - 1] - i + 1 > 0) re *= (sum - v[h - 1] - i + 1);
      re /= (sum - i + 1);
    }
    printf("%.10f", 1 - re);
  }
  return 0;
}
