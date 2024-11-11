#include <bits/stdc++.h>
using namespace std;
int n, K;
double rec(vector<int> a, int op) {
  if (op == K) {
    int inv = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[j] < a[i]) inv++;
    return inv;
  } else {
    double ans = 0;
    int total = (n * (n - 1));
    for (int l = 0; l < n; l++) {
      for (int r = l; r < n; r++) {
        vector<int> b = a;
        for (int k = 0; k < (r - l + 1) / 2; k++) {
          swap(b[l + k], b[r - k]);
        }
        ans += rec(b, op + 1) * (1.0 / (double)total);
      }
    }
    return ans;
  }
}
int main() {
  cin >> n >> K;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  double ans = rec(a, 0);
  printf("%.9f\n", ans);
  return 0;
}
