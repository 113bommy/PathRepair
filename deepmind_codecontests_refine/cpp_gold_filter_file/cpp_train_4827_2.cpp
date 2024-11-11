#include <bits/stdc++.h>
using namespace std;
double x, f[100005], len;
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    f[i] = f[i - 1] + (len * 2 + 1) * x;
    len = (len + 1) * x;
  }
  printf("%.15lf\n", f[n]);
  return 0;
}
