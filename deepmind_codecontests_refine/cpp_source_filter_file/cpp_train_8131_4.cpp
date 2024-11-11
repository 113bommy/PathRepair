#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int x[N], A[N], n, k, sum;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> x[i], A[i] = x[i];
  sort(A, A + n);
  int q = 0;
  for (int i = 0; i < n; i++) {
    if (q == k) break;
    if ((A[i] - sum) > 0) {
      cout << A[i] - sum << endl;
      sum += (A[i] - sum);
      q++;
    }
  }
  if (q < k) {
    for (int i = q; i <= k; i++) cout << "0" << endl;
  }
  cout << endl;
  return 0;
}
