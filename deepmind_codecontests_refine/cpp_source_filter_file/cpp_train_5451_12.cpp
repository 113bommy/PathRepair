#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  int X[8], Y[8], Z[8];
  int x2, y2, z2;
  int A[8];
  int ans = 0;
  cin >> x2 >> y2 >> z2;
  cin >> X[7] >> Y[7] >> Z[7];
  cin >> A[1] >> A[2] >> A[3] >> A[4] >> A[5] >> A[6];
  if (x2 > X[7]) ans += A[6];
  if (z2 > Z[7]) ans += A[4];
  if (y2 > Y[7]) ans += A[2];
  if (y2 < 0) ans += A[1];
  if (z2 < 0) ans += A[5];
  if (z2 < 0) ans += A[3];
  cout << ans << endl;
  return 0;
}
