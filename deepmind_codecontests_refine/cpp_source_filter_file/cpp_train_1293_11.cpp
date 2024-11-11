#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
bool g[maxn][maxn];
int Ke[maxn], Si[maxn], K, cnt;
void Add(int a, int b) { g[a][b] = g[b][a] = 1; }
void work(int x) {
  int c = 62 - 2 * x - 1;
  Add(Si[c], Ke[x]);
}
void do_it() {
  memset(g, 0, sizeof(g));
  Ke[0] = 1;
  cnt = 2;
  for (int i = 1; i < 33; ++i) {
    Add(cnt, cnt - 1);
    cnt++;
    Add(cnt, cnt - 2);
    cnt++;
    Add(cnt, cnt - 2);
    Add(cnt, cnt - 1);
    Ke[i] = cnt++;
  }
  int pre = 0;
  for (int i = 1; i < 65; ++i) {
    Add(cnt, pre);
    Si[i] = cnt;
    pre = cnt++;
  }
  for (int i = 0; i < 32; ++i)
    if ((K >> i) & 1) work(i);
}
int main() {
  while (scanf("%d", &K) != EOF) {
    do_it();
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
      for (int j = 0; j < cnt; ++j) printf("%c", g[i][j] ? 'N' : 'Y');
      printf("\n");
    }
  }
  return 0;
}
