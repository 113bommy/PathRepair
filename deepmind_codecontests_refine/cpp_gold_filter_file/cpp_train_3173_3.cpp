#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int n, k;
int p[maxn];
int col[maxn][maxn];
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) col[i][j] = p[i] / k;
    for (int j = 0; j < p[i] % k; j++) col[i][j]++;
  }
  for (int j = 0; j < k; j++) {
    int a[maxn];
    for (int i = 0; i < n; i++) a[i] = col[i][j];
    sort(a, a + n);
    if (a[n - 1] - a[0] > 1) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      for (int jj = 0; jj < col[i][j]; jj++) cout << j + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}
