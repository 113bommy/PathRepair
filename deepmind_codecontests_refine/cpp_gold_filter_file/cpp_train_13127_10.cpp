#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char s[N];
int pl[N][26], pr[N][26], n;
int pre[N][26], suf[N][26], Xor[N];
int calc(int l, int r) {
  int msk = 0;
  for (int j = (int)(0); j <= (int)(25); j++)
    if (pr[l][j] <= r) {
      int w = Xor[pl[r][j]] ^ Xor[pr[l][j]] ^ suf[l][j] ^ pre[r][j];
      msk |= (1 << w);
    }
  for (int j = (int)(0); j <= (int)(26); j++)
    if (!(msk & (1 << j))) return j;
}
pair<int, int> seg[55 + N];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = (int)(1); i <= (int)(n); i++) s[i] -= 'a';
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(0); j <= (int)(25); j++)
      pl[i][j] = (s[i] == j ? i : pl[i - 1][j]);
  for (int j = (int)(0); j <= (int)(25); j++) pr[n + 1][j] = n + 1;
  for (int i = (int)(n); i >= (int)(1); i--)
    for (int j = (int)(0); j <= (int)(25); j++)
      pr[i][j] = (s[i] == j ? i : pr[i + 1][j]);
  for (int i = (int)(1); i <= (int)(n); i++) {
    int cnt = 0;
    Xor[i] = Xor[pl[i - 1][s[i]]] ^ pre[i - 1][s[i]];
    for (int j = (int)(0); j <= (int)(25); j++)
      if (pl[i][j] != i && pl[i][j])
        seg[++cnt] = pair<int, int>(pl[i][j] + 1, 0);
    if (i != n) {
      int L = pl[i][s[i + 1]];
      for (int j = (int)(L + 1); j <= (int)(i); j++)
        seg[++cnt] = pair<int, int>(j, 1);
    }
    sort(seg + 1, seg + cnt + 1, greater<pair<int, int> >());
    for (int j = (int)(1); j <= (int)(cnt); j++) {
      int w = calc(seg[j].first, i);
      if (seg[j].second)
        suf[seg[j].first][s[i + 1]] = w;
      else
        pre[i][s[seg[j].first - 1]] = w;
    }
  }
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    puts(calc(l, r) ? "Alice" : "Bob");
  }
}
