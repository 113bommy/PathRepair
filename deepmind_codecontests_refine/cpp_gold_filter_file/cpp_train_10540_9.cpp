#include <bits/stdc++.h>
using namespace std;
char str[100010];
int cnt[3];
int aux;
int l, r;
int main() {
  scanf("%s", str);
  int tam = strlen(str);
  cnt[0] = cnt[1] = cnt[2] = 0;
  for (int i = 0; i < tam; i++) {
    if (str[i] == '?')
      cnt[2]++;
    else
      cnt[str[i] - '0']++;
  }
  if (str[tam - 1] == '?')
    aux = 2;
  else
    aux = str[tam - 1] - '0';
  int aa = (tam - 1) / 2;
  int bb = (tam - 2) / 2;
  if (aa >= cnt[1]) puts("00");
  r = aa + 1 - cnt[1];
  l = bb + 1 - cnt[0];
  if (r >= 0 && l >= 0) {
    if (aux == 1)
      puts("01");
    else if (aux == 0)
      puts("10");
    else {
      if (r >= 1) puts("01");
      if (l >= 1) puts("10");
    }
  }
  if (bb >= cnt[0]) puts("11");
  return 0;
}
