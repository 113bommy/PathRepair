#include <bits/stdc++.h>
using namespace std;
const int maxs = 33;
const int maxn = 50000 + 2;
int t, size;
int num[maxs];
int loc[maxs];
int times[maxs];
int ans[maxs];
int n, p;
void Init() {
  int x;
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x < 32) {
      num[t] = x;
      loc[t] = i;
      if (x > 9)
        times[t] = 100;
      else
        times[t] = 10;
      t++;
    }
  }
}
bool f[maxs][maxs][maxn];
void Solve() {
  f[0][num[0]][num[0] % p] = true;
  for (int i = 1; i < t; i++) {
    f[i][num[i]][num[i] % p] = true;
    for (int j = 0; j < maxs; j++)
      for (int k = 0; k < p; k++)
        if (f[i - 1][j][k]) {
          f[i][j][k] = true;
          f[i][j ^ num[i]][(k * times[i] + num[i]) % p] = true;
        }
  }
  if (!f[t - 1][0][0]) {
    printf("No\n");
    return;
  }
  int val = 0, res = 0;
  for (int i = t - 1; i > -1; i--) {
    if (num[i] == val && num[i] % p == res) {
      ans[size++] = i;
      val = 0;
      res = 0;
      break;
    }
    if (i == 0) break;
    for (int j = 0; j < p; j++)
      if ((j * times[i] + num[i]) % p == res && f[i - 1][val ^ num[i]][j]) {
        val = val ^ num[i];
        res = j;
        ans[size++] = i;
        break;
      }
  }
  printf("Yes\n%d\n", size);
  for (int i = size - 1; i > -1; i--) printf("%d ", num[ans[i]]);
  printf("\n");
}
int main() {
  Init();
  Solve();
  return 0;
}
