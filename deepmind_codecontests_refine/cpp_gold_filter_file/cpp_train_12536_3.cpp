#include <bits/stdc++.h>
using namespace std;
bool A[200002];
int main() {
  long long c, m, n, i, j, h, k = 0, ma = -1, ma1, z = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] == 0) z += k;
    k += A[i];
  }
  cout << z;
  return 0;
}
