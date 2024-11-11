#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, k, a[500000];
int f(int x) {
  int t = 2;
  for (int i = 1; i <= n; i++) t *= 2;
  return t - 2;
}
int f1(int x) {
  int t = 1;
  for (int i = 1; i <= x; i++) t *= 2;
  return t;
}
int main() {
  cin >> n;
  for (int i = 1; i <= f(n); i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 2; i--) {
    int t = f1(i) - 1;
    int r = f1(i - 1);
    for (int j = t; j < t + f1(i); j += 2) {
      ans += abs(a[j] - a[j + 1]);
      a[j - r] += max(a[j], a[j + 1]);
      r++;
    }
  }
  cout << ans + abs(a[1] - a[2]);
  return 0;
}
