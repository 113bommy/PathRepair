#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int g[maxn], ps[10][maxn], n;
int f(int x) {
  int ans = 1;
  while (x > 0) {
    if (x % 10) ans *= x % 10;
    x /= 10;
  }
  return ans;
}
void findg() {
  for (int i = 1; i < 10; i++) g[i] = i;
  for (int i = 10; i < maxn; i++) {
    int x = f(i);
    g[i] = g[x];
  }
}
void find_ps() {
  for (int i = 0; i < maxn - 1; i++) {
    for (int k = 1; k < 10; k++) ps[k][i + 1] = ps[k][i];
    ps[g[i]][i + 1]++;
  }
}
int main() {
  findg();
  find_ps();
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    r++;
    cout << ps[k][r] - ps[k][l] << endl;
  }
}
