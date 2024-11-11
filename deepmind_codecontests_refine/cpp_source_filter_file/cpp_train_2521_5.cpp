#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
long long c[1111][1111];
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 1111; i++) c[i][i] = c[i][0] = 1;
  for (int i = 2; i < 1111; i++)
    for (int j = 1; j < i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 1000000007;
  int n, k, m;
  cin >> n >> m >> k;
  cout << (c[n - 1][2 * k] * c[m - 1][2 * k]) % 1000000007;
  return 0;
}
