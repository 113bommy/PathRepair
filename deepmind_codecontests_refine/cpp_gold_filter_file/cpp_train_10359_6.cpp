#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
const int mod = 1e9 + 7;
int a[500005], freq[10000005], pot[500005], qtd[10000005];
bool flag[10000005], bad[10000005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    int root = sqrt(a[i]), x = a[i];
    for (int j = 2; j <= root; j++)
      if (x % j == 0) {
        freq[j]++;
        freq[x / j]++;
      }
    if (x != 1) freq[x]++;
    if (root * root == x) freq[root]--;
  }
  pot[0] = 1;
  for (int i = 1; i <= n; i++) pot[i] = (pot[i - 1] * 2) % mod;
  for (int i = 2; i < maxn; i++)
    if (!flag[i]) {
      for (int j = i; j < maxn; j += i) {
        qtd[j]++;
        flag[j] = 1;
        if (j % (1LL * i * i) == 0) bad[j] = 1;
      }
    }
  int res = 0;
  for (int i = 2; i < maxn; i++) {
    if (bad[i] || freq[i] == 0) continue;
    int aux = (1LL * (pot[freq[i]] - 1 + mod) * (n - freq[i])) % mod;
    if ((qtd[i] & 1) == 0) aux *= -1;
    res += aux;
    if (res >= mod) res -= mod;
    if (res < 0) res += mod;
  }
  cout << res << endl;
  return 0;
}
