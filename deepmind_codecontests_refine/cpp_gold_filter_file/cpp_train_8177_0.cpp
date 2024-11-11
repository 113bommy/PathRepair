#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
bitset<2005> a[2005], inv[2005];
int u[500005], v[500005];
int gauss() {
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int j = i;
    while (j <= n && a[j][i] == 0) j++;
    if (j > n) return 0;
    if (i != j) {
      swap(a[i], a[j]);
      swap(inv[i], inv[j]);
    }
    for (int j = 1; j <= n; j++)
      if (i != j) {
        if (a[j][i] == 1) {
          a[j] ^= a[i];
          inv[j] ^= inv[i];
        }
      }
  }
  return 1;
}
void fmain() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", u + i, v + i);
    a[u[i]][v[i]] = 1;
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++) inv[i][i] = 1;
  int x = gauss();
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    if (x == 0 || inv[v[i]][u[i]] == 1)
      puts("NO");
    else
      puts("YES");
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain();
  }
  return 0;
}
