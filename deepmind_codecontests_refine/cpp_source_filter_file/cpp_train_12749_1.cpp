#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  double a[n];
  for (int i = 0; i < (n); i++) cin >> a[i];
  sort(a, a + n);
  double mx = 0;
  for (int i = 1; i < (n); i++)
    mx = mx > a[i] - a[i - 1] ? mx : a[i] - a[i - 1];
  mx /= 2;
  printf("%.9f", max(mx, max(a[0], n - a[n - 1])));
}
