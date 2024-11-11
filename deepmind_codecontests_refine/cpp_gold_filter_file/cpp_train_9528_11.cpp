#include <bits/stdc++.h>
using namespace std;
long long nCr[605][10];
void pre() {
  for (long long i = 0; i <= 550; i++) nCr[i][0] = 1;
  for (long long i = 1; i <= 550; i++) {
    for (int j = 1; j <= 5; j++)
      nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]);
  }
}
long long n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre();
  cin >> n;
  cout << nCr[n + 4][5] * nCr[n + 2][3] << endl;
  return 0;
}
