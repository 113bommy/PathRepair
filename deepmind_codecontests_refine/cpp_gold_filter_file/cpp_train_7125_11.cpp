#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int L[MAX], R[MAX], a[MAX];
int n;
int main() {
  ios::sync_with_stdio(false);
  int ma = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  L[0] = R[n - 1] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1])
      L[i] = L[i - 1] + 1;
    else
      L[i] = 1;
    ma = max(ma, L[i]);
  }
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] < a[i + 1])
      R[i] = R[i + 1] + 1;
    else
      R[i] = 1;
    ma = max(ma, R[i]);
  }
  int res = min(ma + 1, n);
  for (int i = 1; i < n - 1; i++) {
    if (a[i] > a[i - 1] && a[i] < a[i - 1]) continue;
    if (a[i] <= a[i - 1] && a[i + 1] - a[i - 1] > 1)
      res = max(res, L[i - 1] + R[i]);
    if (a[i] >= a[i + 1] && a[i + 1] - a[i - 1] > 1)
      res = max(res, L[i] + R[i + 1]);
  }
  cout << res;
}
