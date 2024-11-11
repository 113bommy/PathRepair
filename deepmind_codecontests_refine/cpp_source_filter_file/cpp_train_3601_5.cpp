#include <bits/stdc++.h>
using namespace std;
vector<int> st[200010], ed[200010];
unsigned long long f[200010];
unsigned long long bmask[200010], emask[200010];
unsigned long long val[200010];
map<unsigned long long, unsigned long long> cnt, sum;
int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  unsigned long long ans = 0, all = 0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    st[a].push_back(i);
    ed[b].push_back(i);
    unsigned long long v = ((unsigned long long)rand() << 40) +
                           ((unsigned long long)rand() << 20) +
                           (unsigned long long)rand();
    val[i] = v;
    f[a] ^= v;
    f[b + 1] ^= v;
    all ^= v;
  }
  for (int i = 1; i <= n; i++) f[i] ^= f[i - 1];
  for (int i = 1; i <= n; i++) {
    if (f[i]) continue;
    int st = i;
    while (!f[st] && st <= n) st++;
    st--;
    int len = st - i + 1;
    ans -= (unsigned long long)len * (len + 1) * (len + 2) / 6;
    i = st;
  }
  for (int i = 1; i <= n; i++) f[i] ^= f[i - 1];
  unsigned long long mask = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < ed[i].size(); j++) {
      int id = ed[i][j];
      mask ^= val[id];
    }
    emask[i] = mask;
  }
  mask = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < st[i].size(); j++) {
      int id = st[i][j];
      mask ^= val[id];
    }
    bmask[i] = mask;
  }
  cnt[0] = 1;
  for (int R = 1; R <= n; R++) {
    unsigned long long v = all ^ f[R] ^ bmask[R + 1];
    ans += cnt[v] * (unsigned long long)R + sum[v];
    unsigned long long vv = emask[R] ^ f[R];
    sum[vv] += R;
    cnt[vv]--;
  }
  cout << ans << endl;
  return 0;
}
