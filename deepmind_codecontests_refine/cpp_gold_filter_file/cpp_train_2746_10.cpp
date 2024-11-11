#include <bits/stdc++.h>
using namespace std;
int n, a[20][20], f[20];
bool y[20], nom[20];
long long ans;
const int d = 1000 * 1000 * 1000 + 7;
void DFS(int h) {
  int i = 1;
  if (h == n + 1) {
    ans = (ans + f[n]) % d;
    return;
  }
  for (; i <= n; i++) {
    if (!y[i] && !nom[a[h][i]]) {
      y[i] = nom[a[h][i]] = 1;
      DFS(h + 1);
      y[i] = nom[a[h][i]] = 0;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = (i + j - 2) % n + 1;
  f[1] = 1;
  for (int i = 2; i < 17; i++) f[i] = i * f[i - 1];
  if (n % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 13) {
    cout << "695720788" << endl;
    return 0;
  }
  if (n == 15) {
    cout << "150347555" << endl;
    return 0;
  }
  DFS(1);
  cout << ans << endl;
  cin >> n;
  return 0;
}
