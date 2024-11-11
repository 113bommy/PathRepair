#include <bits/stdc++.h>
using namespace std;
long long x, y, n, m, i, j, k;
long long deg[1000001];
int main() {
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    deg[x]++;
    deg[y]++;
  }
  long long sum = 0;
  for (i = 1; i <= n; i++) {
    long long k = deg[i];
    sum += k * (k - 1ll);
  }
  sum /= 2;
  cout << n * (n - 1) * (n - 2) / 6 - m * (n - 2ll) + sum << endl;
  return 0;
}
