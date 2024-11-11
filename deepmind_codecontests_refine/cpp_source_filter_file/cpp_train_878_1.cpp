#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > hop;
set<pair<int, int> >::iterator it;
int best[1010], ju[1010][1010], val[1010], fir[1010];
int st[1010], en[1010], w[1010], s[1010], v[1010];
int I[1010];
bool cmp(int t, int k) {
  if (en[t] < en[k]) return true;
  if (en[t] > en[k]) return false;
  if (st[t] > st[k]) return true;
  return false;
}
int main() {
  int N, S, t, x, r, y;
  pair<int, int> p;
  scanf("%d%d", &N, &S);
  hop.clear();
  for (int i = (1); i < (N + 1); i++) I[i] = i;
  for (int i = (1); i < (N + 1); i++)
    scanf("%d%d%d%d%d", st + i, en + i, w + i, s + i, v + i);
  sort(I + 1, I + N + 1, cmp);
  for (int i = (1); i < (N + 1); i++) {
    for (int j = (1); j < (i); j++)
      if (en[I[j]] > st[I[i]]) {
        fir[i] = j - 1;
        break;
      }
  }
  for (int i = (1); i < (N + 1); i++) {
    t = I[i];
    for (int k = (0); k < (S + 1); k++) {
      if (w[t] > k) continue;
      y = min(k - w[t], s[t]);
      memset(val, 0, sizeof(int) * (i + 1));
      for (int j = (1); j < (i); j++) {
        val[j] = val[j - 1];
        if (st[I[j]] < st[t]) continue;
        x = ju[j][y];
        x += val[fir[j]];
        val[j] = max(val[j], x);
      }
      ju[i][k] = val[i - 1] + v[t];
    }
  }
  for (int i = (1); i < (N + 1); i++) {
    t = I[i];
    x = fir[i];
    best[i] = best[i - 1];
    best[i] = max(best[i], ju[i][S] + best[x]);
  }
  printf("%d\n", best[N]);
  return 0;
}
