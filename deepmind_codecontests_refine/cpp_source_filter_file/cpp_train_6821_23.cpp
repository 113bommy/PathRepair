#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int maxn = 5e3 + 5;
int A[maxn][maxn];
int row[maxn], col[maxn], timerow[maxn], timecol[maxn];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int p = k;
  while (k--) {
    int i, a, b;
    cin >> i >> a >> b;
    i--;
    if (!i)
      row[a] = b, timerow[a] = p - k;
    else
      col[a] = b, timecol[a] = p - k;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (timerow[i] < timerow[j])
        A[i][j] = col[j];
      else
        A[i][j] = row[i];
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << A[i][j] << " ";
    cout << endl;
  }
  return 0;
}
