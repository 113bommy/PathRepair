#include <bits/stdc++.h>
using namespace std;
int n, K;
int a[100111];
long long po[100111];
bool vis[100111];
int p[100111], pcnt, cc[100111];
map<int, int> cnt;
int main() {
  scanf("%d", &n);
  scanf("%d", &K);
  for (int i = 2; i < 100111; i++) {
    if (!vis[i]) p[++pcnt] = i;
    for (int j = 1, k; (k = i * p[j]) < 100111; j++) {
      vis[k] = 1;
      if (i % p[j] == 0) break;
    }
  }
  for (int i = 1; i <= int(1e5 + 5); i++) {
    po[i] = 1;
    if (po[i - 1] > 1e13)
      po[i] = po[i - 1];
    else
      for (int k = 1; k <= K; k++) {
        po[i] *= i;
        if (po[i] > 1e13) break;
      }
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (int j = 2; po[j] <= a[i]; j++) {
      while (a[i] % po[j] == 0) a[i] /= int(po[j]);
    }
    long long co = 1, cura = a[i];
    for (int j = 2; co != -1 && j * j <= cura; j++)
      if (!vis[j]) {
        if (a[i] % j == 0) {
          long long q = j;
          while (a[i] % q == 0) q *= j;
          q /= j;
          cura /= q;
          if ((double)co * po[j] / q > 100111)
            co = -1;
          else
            co *= po[j] / q;
        }
      }
    if (co > 0 && cura > 1) {
      if ((double)co * po[cura] / cura > 100111)
        co = -1;
      else
        co *= po[cura] / cura;
    }
    if (co > 0 && co < 100111) {
      cc[i] = co;
    }
  }
  long long ans = 0;
  for (int i = n; i; i--) {
    if (cc[i] > 0) ans += cnt[cc[i]];
    cnt[a[i]]++;
  }
  cout << ans << endl;
}
