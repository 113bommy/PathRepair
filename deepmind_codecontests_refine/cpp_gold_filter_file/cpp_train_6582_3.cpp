#include <bits/stdc++.h>
using namespace std;
const int N = 61;
long long C[N][N];
int main() {
  C[1][0] = C[1][1] = 1;
  for (int i = 2; i < N; i++) {
    C[i][0] = 1;
    for (int j = 1; j < N; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
  }
  long long n, b, g, i;
  cin >> b >> g >> n;
  long long num = 0;
  for (i = 4; i < n; i++) num += C[b][i] * C[g][n - i];
  cout << num << endl;
  return 0;
}
