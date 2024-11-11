#include <bits/stdc++.h>
using namespace std;
map<int, int> dp[25][100];
int n, fin, m, SI;
int mang[25], a[25], b[25], mu[10];
void inkq() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (((mang[j] >> i - 1) & 1) == 1)
        cout << '*';
      else
        cout << '.';
    }
    cout << endl;
  }
  exit(0);
}
int get(int i, int p) { return (p / mu[i]) % 12; }
void DUYET(int col, int tt, int sum) {
  if (col == m + 1) {
    if (sum == fin) inkq();
    return;
  }
  if (dp[col][tt][sum] == 1) return;
  dp[col][tt][sum] = 1;
  for (int i = 0; i <= SI; i++) {
    int dem = ((i >> 0) & 1);
    for (int j = 1; j < n; j++)
      if ((((i >> j) & 1) != ((i >> j - 1) & 1)) && ((i >> j) & 1) == 1) dem++;
    if (dem != b[col]) continue;
    int p = sum;
    for (int j = 0; j < n; j++)
      if (((tt >> j) & 1) == 0 && ((i >> j) & 1) == 1) p += mu[j];
    int ok = 1;
    for (int j = 0; j <= 4; j++)
      if (get(j, p) > a[j + 1] || get(j, p) + (m - i + 1) / 2 < a[j + 1]) {
        ok = 0;
        break;
      }
    if (ok == 0) continue;
    mang[col] = i;
    DUYET(col + 1, i, p);
  }
}
int main() {
  cin >> n >> m;
  mu[0] = 1;
  for (int i = 1; i <= 7; i++) mu[i] = mu[i - 1] * 12;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    fin += a[i] * mu[i - 1];
  }
  for (int i = 1; i <= m; i++) cin >> b[i];
  SI = (1 << n) - 1;
  DUYET(1, 0, 0);
}
