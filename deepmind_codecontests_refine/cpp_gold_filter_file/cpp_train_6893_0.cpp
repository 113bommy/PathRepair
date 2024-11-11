#include <bits/stdc++.h>
using namespace std;
const int mac = 2e3 + 10;
int a[mac], vis[mac];
int ask(int pos) {
  printf("? %d\n", pos + 1);
  fflush(stdout);
  char s[5];
  scanf("%s", s);
  if (s[0] == 'Y') return 1;
  return 0;
}
int main(int argc, char const *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  int block = m / 2;
  if (!block) block = 1;
  int nb_block = n / block;
  if (block != 1) {
    for (int i = 0; i < nb_block; i++) {
      int st = i * block;
      for (int j = st; j < st + block; j++) {
        if (!vis[j])
          if (ask(j)) vis[j] = 1;
      }
      printf("R\n");
      fflush(stdout);
    }
  }
  for (int i = 0; i < nb_block; i++) {
    for (int j = i + 1; j < nb_block; j++) {
      int st = i * block;
      for (int k = st; k < st + block; k++)
        if (!vis[k]) ask(k);
      st = j * block;
      for (int k = st; k < st + block; k++)
        if (!vis[k])
          if (ask(k)) vis[k] = 1;
      printf("R\n");
      fflush(stdout);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (!vis[i]) ans++;
  printf("! %d\n", ans);
  fflush(stdout);
  return 0;
}
