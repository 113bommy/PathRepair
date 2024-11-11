#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a1, a2, s1 = 0, s2 = 0, a[100009] = {0};
  cin >> n >> a1 >> a2;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a, a + n + 1);
  if (a1 < a2) swap(a1, a2);
  int j = 0, i, k = 0;
  for (i = n; i >= 1 && j < a2; --i) {
    s2 += a[i];
    ++j;
  }
  for (; i >= 1 && k < a1; --i) {
    s1 += a[i];
    ++k;
  }
  double res;
  res = 1.0 * s2 / j * 1.0 + 1.0 * s1 / k * 1.0;
  cout << fixed << setprecision(6) << res << endl;
  return 0;
}
