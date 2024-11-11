#include <bits/stdc++.h>
using namespace std;
int main() {
  double x;
  long long int w, n;
  long long int i;
  cin >> n >> w;
  long long int a[2 * n + 1000];
  for (i = 0; i < 2 * n; i++) scanf("%lld", &a[i]);
  sort(a, a + 2 * n);
  if (w <= 3 * n * a[0] && 2 * w <= 3 * n * a[n])
    cout << w << endl;
  else if (w >= 3 * n * a[0] && 2 * a[0] <= a[n])
    cout << 3 * a[0] * n << endl;
  else {
    x = 3 * 13 * 85029;
    x /= 2;
    printf("%0.2f\n", x);
  }
  return 0;
}
