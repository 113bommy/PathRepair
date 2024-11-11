#include <bits/stdc++.h>
using namespace std;
int n, a, b, f[35000][40];
long long ksm(int k, int p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret *= k;
    k *= k;
    p >>= 1;
    if (ret >= n) return -1;
  }
  return ret;
}
void dfs(int a, int b) {
  if (f[a][b] != 0) return;
  long long k = ksm(a, b);
  if (k >= n || k == -1) {
    f[a][b] = 1;
    return;
  }
  if (b == 1 && a * a >= n) {
    if (a % 2 == n % 2)
      f[a][b] = 1;
    else
      f[a][b] = -1;
    return;
  }
  dfs(a + 1, b);
  dfs(a, b + 1);
  if (f[a + 1][b] == 1 && f[a][b + 1] == 1)
    f[a][b] = -1;
  else
    f[a][b] = 1;
}
int main() {
  cin >> a >> b >> n;
  if (a == 1 && ksm(2, b) == -1) {
    cout << "Missing";
    return 0;
  }
  dfs(a, b);
  if (f[a][b] == 1)
    cout << "Masha" << endl;
  else
    cout << "Stas" << endl;
}
