#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n;
  cin >> m;
  int A[n], B[m];
  for (i = 0; i < n; i++) cin >> A[i];
  for (j = 0; j < m; j++) cin >> B[j];
  for (j = 0; j < n; j++) {
    for (i = 0; i < m; i++) {
      if (A[j] == B[i]) cout << A[j];
    }
  }
  return 0;
}
