#include <bits/stdc++.h>
using namespace std;
int main() {
  string q;
  int n, m, k = 0, sum1 = 0, sum2 = 0, t;
  cin >> n >> m;
  int A[n];
  pair<int, string> B[m];
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  for (int i = 0; i < m; i++) {
    cin >> q;
    t = 1;
    if (k == 0) {
      B[0].second = q;
      B[0].first = 1;
      k++;
    } else {
      for (int j = 0; j < k; j++) {
        if (B[j].second == q) {
          B[j].first++;
          t = 0;
        }
      }
      if (t == 1) {
        B[k].second = q;
        B[k].first = 1;
        k++;
      }
    }
  }
  sort(B, B + k);
  for (int i = k - 1; i >= 0; i--) sum1 += (A[k - 1 - i] * B[i].first);
  for (int i = k - 1; i >= 0; i--) sum2 += (A[n - 1 - k + 1 + i] * B[i].first);
  cout << sum1 << " " << sum2;
}
