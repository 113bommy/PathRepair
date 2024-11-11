#include <bits/stdc++.h>
using namespace std;
long long p[2048][2048];
int main() {
  for (int i = 1; i <= 2000; i++) {
    p[i][0] = 1;
    for (int j = 1; j <= 2000; j++) p[i][j] = (p[i][j - 1] * i) % 1000000007;
  }
  int m, n, k;
  cin >> n >> m >> k;
  if (k == 1 || n < k)
    cout << (long long)p[m][n] % 1000000007;
  else if (k == n)
    cout << (long long)p[m][(n + 1) / 2] % 1000000007;
  else if (k % 2)
    cout << (m * m) % 1000000007;
  else
    cout << m;
  cout << endl;
  return 0;
}
