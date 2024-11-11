#include <bits/stdc++.h>
using namespace std;
int solve(int k, int a) {
  int res = 0, mid = 0;
  int n = a;
  if (n < 4) return 1;
  while (n != 1) {
    if (n < 4) {
      mid = 1;
      break;
    }
    if (n % 4 != 0) mid = 1;
    n = n / 4;
    res++;
  }
  return res + mid + k;
}
int main() {
  int n, k, a, p, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    cin >> a;
    p = solve(k, a);
    res = max(res, p);
  }
  cout << res;
  return 0;
}
