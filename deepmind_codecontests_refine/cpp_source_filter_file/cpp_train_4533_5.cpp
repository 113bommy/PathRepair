#include <bits/stdc++.h>
using namespace std;
char str[22][100100];
int M[22][100100];
int v[100100];
int n, m;
bool cmp(int a, int b) {
  for (int i = 0; i < n; i++)
    if (str[i][a] != str[i][b]) return str[i][a] < str[i][b];
  return 0;
}
int qlast[100100];
int mask[100100];
int coisa[100100][20];
int add[100100][20];
int pref[100100];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf(" %s", str[i]);
  for (int i = 0; i < m; i++) v[i] = i;
  sort(v, v + m, cmp);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      M[i][j] = (str[i][v[j]] == '1') ? 1 : 0;
      ;
    };
  }
  int up = n / 2;
  int down = n - up;
  for (int j = 0; j < (1 << n); j++)
    for (int i = up; i < n; i++)
      if (j & (1 << i)) qlast[j]++;
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++) mask[j] += M[i][j] * (1 << i);
  for (int i = 0; i < m; i++)
    ;
  int filter = (1 << up) - 1;
  int ans = (int)n * m;
  for (int i = 0; i < (1 << down); i++) {
    int qnt = 0;
    int last = 0;
    for (int j = 0; j < m; j++)
      if (j == m - 1 || (mask[j] & filter) != (mask[j + 1] & filter)) {
        ;
        pref[qnt] = (mask[j] & filter);
        for (int k = 0; k < 20; k++) coisa[qnt][k] = 0;
        for (int k = last; k <= j; k++) {
          coisa[qnt][__builtin_popcount(((mask[k] >> up) ^ i))]++;
        }
        for (int k = 0; k <= up; k++) {
          add[qnt][k] = 0;
          for (int l = 0; l <= down; l++)
            add[qnt][k] += (long long)coisa[qnt][l] * min(l + k, n - l - k);
          ;
        }
        last = j + 1;
        qnt++;
      }
    for (int ii = 0; ii < (1 << up); ii++) {
      int cur = 0;
      for (int j = 0; j < qnt; j++)
        cur += add[j][__builtin_popcount(pref[j] ^ ii)];
      ans = min(ans, cur);
    }
  }
  cout << ans << endl;
}
