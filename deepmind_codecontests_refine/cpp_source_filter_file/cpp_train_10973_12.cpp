#include <bits/stdc++.h>
using namespace std;
const int maxn = 2020;
const int maxx = 10000;
const int MOd = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOd) a -= MOd;
}
int mul(int a, int b) { return (long long)a * b % MOd; }
int a, K, dn[maxn][maxn], top[maxn];
char ar[maxn];
int main() {
  scanf("%d %d", &a, &K);
  scanf(" %s", ar + 1);
  for (int i = 1; i <= a; i++) ar[i] = i[ar] - 'a';
  dn[0][0] = 1;
  top[0] = 1;
  for (int i = 1; i <= a; i++) {
    for (int j = 0; j <= K; j++) {
      if (ar[i] != 25) {
        int h = a - i + 1;
        for (int k = i - 1; k >= 0 && (i - k) * h <= j; k--) {
          add(dn[i][j], mul(dn[k][j - (i - k) * h], 25 - ar[i]));
        }
      }
      if (ar[i]) {
        add(dn[i][j], mul(top[j], ar[i]));
      }
      add(top[j], dn[i][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= a; i++) add(ans, dn[i][K]);
  cout << ans << endl;
  return 0;
}
