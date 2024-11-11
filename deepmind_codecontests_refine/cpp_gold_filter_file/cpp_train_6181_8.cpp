#include <bits/stdc++.h>
using namespace std;
int n;
long long data[100050], input[100050];
int mark[100050], w[64];
int num[64], ans[64], que[64];
bool mat[100050][64];
void writ(long long x) {
  printf(" ");
  for (int i = 9; i >= 0; i--)
    if ((x & (1ll << i)))
      printf("1");
    else
      printf("0");
}
long long com(long long x, int k) {
  return (-1ll ^ ((1ll << k) - 1)) & x;
  return x;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &data[i]);
    input[i] = data[i];
    for (int l = 0; l < 64; l++)
      if (data[i] & (1ll << l)) num[l] ^= 1;
  }
  int cnt = 0;
  for (int l = 63; l >= 0; l--)
    if (!num[l]) que[cnt++] = l;
  for (int l = 63; l >= 0; l--)
    if (num[l]) que[cnt++] = l;
  long long now = 0;
  for (int k = 0; k < cnt; k++) {
    int l = que[k];
    for (int i = 0; i < n; i++)
      if (!mark[i] && (data[i] & (1ll << l))) {
        mark[i] = true;
        w[l] = i;
        for (int j = 0; j < n; j++)
          if (!mark[j] && (data[j] & (1ll << l))) {
            data[j] ^= data[i];
            mat[j][l] = 1;
          }
        if (now & (1ll << l)) continue;
        now ^= data[i];
        ans[l]++;
        break;
      }
  }
  memset(mark, 0, sizeof(mark));
  for (int k = cnt - 1; k >= 0; k--) {
    int l = que[k];
    if (w[l] == -1 || ans[l] % 2 == 0) continue;
    mark[w[l]] = 1;
    for (int j = 0; j < 64; j++)
      if (mat[w[l]][j]) ans[j]++;
  }
  long long a, b;
  a = b = 0;
  for (int i = 0; i < n; i++) {
    printf("%d%c", mark[i] ? 2 : 1, i == n - 1 ? '\n' : ' ');
    if (mark[i])
      a ^= input[i];
    else
      b ^= input[i];
  }
  return 0;
}
