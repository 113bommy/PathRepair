#include <bits/stdc++.h>
using namespace std;
int A[3][100025];
int B[100005][15];
int k;
int tv(int t, int n) {
  if (t > k) {
    if (A[0][t] == 1)
      return max(tv(A[1][t], n), tv(A[2][t], n));
    else
      return min(tv(A[1][t], n), tv(A[2][t], n));
  } else
    return B[t][n];
}
int main() {
  int n, p;
  cin >> n >> k >> p;
  for (int i = 1; i <= k; i++)
    for (int k = 1; k <= n; k++) cin >> B[i][k];
  int t = k + 1;
  for (int i = 1; i <= p; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < 3) {
      if (a == 1)
        A[0][t] = 1;
      else
        A[0][t] = -1;
      A[1][t] = b;
      A[2][t] = c;
      t++;
    } else
      cout << tv(b, c) << endl;
  }
}
