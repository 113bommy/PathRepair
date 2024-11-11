#include <bits/stdc++.h>
using namespace std;
int x[1005], r;
long double y[1005];
int n;
inline long double touch(int i, int j) {
  if (x[i] > (2 * r + x[j]) || x[i] < (x[j] - 2 * r)) return -1.0;
  long double dd = sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j]));
  long double res = y[j] + dd;
  return res;
}
int main() {
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  long double ans;
  for (int i = 0; i < n; i++) {
    ans = r;
    for (int j = 0; j < i; j++) {
      ans = max(ans, touch(i, j));
    }
    y[i] = ans;
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << setprecision(10) << y[i];
  }
  cout << endl;
  return 0;
}
