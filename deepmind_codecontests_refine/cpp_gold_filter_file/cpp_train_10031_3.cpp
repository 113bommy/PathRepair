#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int BUCKET_SZ = 320;
int v[MAXN];
vector<int> f;
int cnt[MAXN];
int sum[MAXN][505];
int n;
int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if (v[i] <= 100000) cnt[v[i]]++;
  }
  int c = 0;
  for (int i = 1; i <= 100000; i++) {
    if (i <= cnt[i]) {
      f.push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < f.size(); j++) {
      int valor = f[j];
      if (valor == v[i]) sum[i][j]++;
      if (i) sum[i][j] += sum[i - 1][j];
    }
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--, r--;
    int ans = 0;
    for (int j = 0; j < f.size(); j++) {
      int valor = f[j];
      int suma = sum[r][j];
      if (l) suma -= sum[l - 1][j];
      if (suma == valor) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
