#include <bits/stdc++.h>
using namespace std;
long long aa[100005][2];
int cmp(const void *aa, const void *bb) {
  long long *a = (long long *)aa;
  long long *b = (long long *)bb;
  if (*a != *b)
    return *a - *b;
  else
    return *(a + 1) - *(b + 1);
}
int main() {
  int n, ans = 0, k = 0;
  long long d, a, b, x, y;
  cin >> n >> d >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    aa[i][0] = a * x + b * y;
    aa[i][1] = (long long)(i + 1);
  }
  qsort(aa, n, sizeof(aa[0]), cmp);
  for (int i = 0; i < n; i++) {
    if (d >= aa[i][0]) {
      ans++;
      d -= aa[i][0];
      if (i == n - 1) k = n;
    } else {
      k = i;
      break;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < k; i++) {
    cout << aa[i][1] << ' ';
  }
  return 0;
}
