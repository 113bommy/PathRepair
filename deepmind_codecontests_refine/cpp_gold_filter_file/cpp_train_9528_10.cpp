#include <bits/stdc++.h>
using namespace std;
long long poww(long long A, long long B) {
  if (!B) return 1;
  long long h = poww(A, B / 2);
  h *= h;
  if (B % 2) h *= A;
  return h;
}
long long gcd(long long A, long long B) {
  return A > B ? gcd(B, A) : A ? gcd(B % A, A) : B;
}
long long ans[5002][6][4];
int main() {
  int n, i, j, ix, jx, iix, jjx;
  cin >> n;
  ans[0][0][0] = 1;
  for (i = 1; i <= n; i++)
    for (ix = 0; ix <= 5; ix++)
      for (jx = 0; jx <= 3; jx++)
        for (iix = 0; iix + ix <= 5; iix++)
          for (jjx = 0; jjx + jx <= 3; jjx++)
            ans[i][ix + iix][jx + jjx] += ans[i - 1][ix][jx];
  cout << ans[n][5][3] << endl;
}
