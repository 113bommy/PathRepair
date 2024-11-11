#include <bits/stdc++.h>
using namespace std;
long long kk[10] = {1,      10,      100,      1000,      10000,
                    100000, 1000000, 10000000, 100000000, 1000000000};
map<long long, int> flag;
int id[11], a[11], n, ans;
long long Cantor(int p[]) {
  long long tmp = 0;
  for (int i = 1; i <= n; i++) tmp = tmp + (long long)p[i] * kk[i - 1];
  return tmp;
}
void dfs(int p[]) {
  long long tmp;
  if (tmp = Cantor(p)) {
    if (!flag[tmp]) ans++, flag[tmp]++;
  }
  bool FLAG = true;
  for (int x = 1; x <= n; x++) {
    if (a[x] >= 1) {
      FLAG = false;
      a[x] -= 1;
      for (int i = 1; i <= n; i++)
        if (a[i] && i != x) {
          int p1 = p[x], p2 = p[i], t1 = a[i];
          swap(p[x], p[i]), a[i]--;
          dfs(p);
          p[x] = p1, p[i] = p2, a[i] = t1;
        }
      a[x] += 1;
    }
    if (a[x] == 2) {
      a[x] -= 2;
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          if (i != x && a[i] && a[j] && i != j) {
            FLAG = false;
            int p1 = p[x], p2 = p[i], p3 = p[j], t1 = a[i], t2 = a[j];
            swap(p[x], p[i]), swap(p[x], p[j]);
            a[i]--, a[j]--;
            dfs(p);
            p[x] = p1, p[i] = p2, p[j] = p3, a[i] = t1, a[j] = t2;
            swap(p[x], p[j]), swap(p[x], p[i]);
            a[i]--, a[j]--;
            dfs(p);
            p[x] = p1, p[i] = p2, p[j] = p3, a[i] = t1, a[j] = t2;
          }
      a[x] += 2;
    }
  }
  if (FLAG) return;
}
int f[501][501];
int main() {
  cin >> n;
  f[1][0] = 1, f[1][1] = 1;
  f[2][0] = 2;
  f[3][0] = 4;
  f[4][0] = 10, f[5][0] = 26;
  f[6][0] = 76, f[7][0] = 232;
  f[8][0] = 764, f[9][0] = 2620;
  f[10][0] = 9496;
  for (int i = 2; i <= 10; i++)
    for (int j = 1; j <= i; j++)
      f[i][j] = f[i - 1][j - 1] * i, f[i][j] %= 1000000007;
  int kk = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]), id[i] = i;
    if (a[i] == 2) kk++;
  }
  cout << f[n][kk] << endl;
  return 0;
}
