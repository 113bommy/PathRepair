#include <bits/stdc++.h>
using namespace std;
long long A[300001], B[300001], n, m;
bool solve(long long t) {
  long long i = 1, j = 1;
  for (; i <= n && j <= m; i++) {
    long long k = i;
    while (k <= n && A[k] <= B[j]) k++;
    if (i != k) i = k - 1;
    if (A[i] <= B[j]) {
      while (j <= m && A[i] + t >= B[j]) j++;
    } else {
      if (t - A[i] + B[j] < 0) {
        return false;
      }
      long long p = max((t - 2 * (A[i] - B[j])), (t - A[i] + B[j]) / 2);
      j++;
      while (j <= m && A[i] + p >= B[j] && p) j++;
    }
  }
  if (j > m) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= m; i++) cin >> B[i];
  long long l = 0, h = 1000000000000000;
  while (l < h) {
    long long m = (l + h) / 2;
    if (solve(m))
      h = m;
    else
      l = m + 1;
  }
  cout << h << endl;
}
