#include <bits/stdc++.h>
using namespace std;
char buf[100001];
struct S {
  char c;
  int q;
} sum[30];
bool cmp(S a, S b) { return a.q < b.q; }
int main() {
  int N, M, L, len;
  gets(buf);
  scanf("%d", &N);
  len = strlen(buf);
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i < 26; i++) sum[i].c = 'a' + i;
  for (int i = 0; i < len; i++) {
    sum[buf[i] - 'a'].q++;
  }
  sort(sum, sum + 26, cmp);
  bool vis[26];
  memset(vis, 0, sizeof(vis));
  int p, q;
  for (p = 0, q = N; p < 26; p++) {
    q -= sum[p].q;
    if (q >= 0) vis[sum[p].c - 'a'] = true;
    if (q <= 0) break;
  }
  printf("%d\n", 26 - p);
  for (int i = 0; i < len; i++)
    if (!vis[buf[i] - 'a']) putchar(buf[i]);
  printf("\n");
  return 0;
}
