#include <bits/stdc++.h>
using namespace std;
int n, a[101];
int p1() {
  int d = a[2] - a[1];
  for (int i = 3; i <= n; i++)
    if (a[i] - a[i - 1] != d) return 1e9;
  return d + a[n];
}
double p2() {
  double d = (double)a[2] / a[1];
  for (int i = 3; i <= n; i++)
    if ((double)a[i] / a[i - 1] != d) return 1e9;
  return d * a[n];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << p1();
  return 0;
}
