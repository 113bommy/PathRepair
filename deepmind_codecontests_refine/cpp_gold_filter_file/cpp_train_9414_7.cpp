#include <bits/stdc++.h>
using namespace std;
const int nmax = 200;
const long double pi = M_PI;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
int n, k, m, a[nmax][nmax], now[nmax], block[nmax];
bool used[nmax];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  for (int i = 0; i < k; i++) {
    used[i] = false;
    now[i] = -1;
  }
  for (int i = 0; i < n; i++) block[i] = -1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) now[j] = -1;
    for (int j = 0; j < n; j++) {
      if (block[j] != -1 || a[j][i] == -1) continue;
      if (now[a[j][i]] == -1)
        now[a[j][i]] = j;
      else {
        block[j] = i;
        block[now[a[j][i]]] = i;
        used[a[j][i]] = true;
      }
      if (used[a[j][i]]) block[j] = i;
    }
  }
  for (int i = 0; i < n; i++) cout << block[i] + 1 << endl;
}
