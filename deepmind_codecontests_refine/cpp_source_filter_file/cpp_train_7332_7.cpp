#include <bits/stdc++.h>
using namespace std;
long long n, i, b, x, y, z;
double m;
pair<double, int> a[10000];
int main() {
  cin >> n >> b;
  for (i = 1; i <= n; i++) {
    cin >> x >> y >> z;
    a[i].first = sqrt(x * x + y * y);
    a[i].second = z;
  }
  sort(a + 1, a + n + 1);
  i = 1;
  while (b < 1000000 && i < n) {
    m = a[i].first;
    b = b + a[i].second;
    i++;
  }
  if (b >= 1000000 && m <= 10000)
    cout << setprecision(9) << m;
  else
    cout << "-1";
}
