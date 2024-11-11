#include <bits/stdc++.h>
using namespace std;
void ent(int n, int a[], int st = 0) {
  for (int i = st; i < n; i++) scanf("%d", a + i);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i <= n - 1; i++)
      for (int j = 0; j <= m - 1; j++) cin >> a[i][j];
    int cnt = 0;
    for (int i = 0; i <= n - 2; i++)
      if (a[i][m - 1] == 'R') cnt++;
    for (int i = 0; i <= m - 2; i++)
      if (a[n - 1][i] == 'R') cnt++;
    cout << cnt;
    cout << endl;
  }
  return 0;
}
