#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, n1, k, s, s1, m, i, j, A[1000];
  m = -1;
  s1 = 0;
  cin >> n >> n1;
  for (i = 0; i < n; ++i) {
    cin >> A[i];
    if (A[i] > m) m = A[i];
  }
  for (i = n1; i <= m; ++i) {
    s = 0;
    for (j = 0; j < n; ++j) {
      s += A[j] / n1;
    }
    if (s * i > s1) s1 = s * i;
  }
  cout << s1;
  return 0;
}
