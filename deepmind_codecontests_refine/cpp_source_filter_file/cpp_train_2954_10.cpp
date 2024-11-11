#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int sg[1100000];
int vis[110];
int main() {
  int n;
  int i, j, k;
  int is1, is2;
  for (i = 2; i <= 60000; i++) {
    for (j = 0; j < i; j++)
      if (j * j * j * j >= i && j * j <= i)
        vis[sg[j]] = i;
      else if (j * j > i)
        break;
    for (j = 0; vis[j] == i; j++)
      ;
    sg[i] = j;
  }
  int ans = 0;
  scanf("%d", &n);
  long long tmp;
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &tmp);
    if (tmp >= 50626ll * 50626)
      j = 0;
    else if (tmp >= 50626)
      j = 1;
    else
      j = sg[tmp];
    ans ^= j;
  }
  if (ans)
    puts("Furlo");
  else
    puts("Rublo");
}
