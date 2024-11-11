#include <bits/stdc++.h>
using namespace std;
char s[100010];
int f[100010][26], n, res;
long long ans;
int K, L, R, pl[510], pr[510], c[510], vl[510], vr[510], cnt[510];
void modify(int p, int v) {
  res -= (cnt[p] >= L && cnt[p] <= R);
  cnt[p] += v;
  res += (cnt[p] >= L && cnt[p] <= R);
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    memcpy(f[i], f[i - 1], sizeof(f[i]));
    f[i][s[i] - 'a']++;
  }
  scanf("%d%d%d", &K, &L, &R);
  for (int i = 1; i <= K; i++) {
    char s[5];
    scanf("%s%d%d", s, &vl[i], &vr[i]);
    c[i] = s[0] - 'a';
    pl[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    res += !L;
    for (int j = 1; j <= K; j++) {
      while (pr[j] < i && f[i][c[j]] - f[pr[j]][c[j]] >= vl[j])
        modify(++pr[j], 1);
      while (pl[j] <= pr[j] && !(f[i][c[j]] - f[pl[j] - 1][c[j]] <= vr[j]))
        modify(pl[j]++, -1);
    }
    ans += res;
  }
  printf("%lld\n", ans);
  return 0;
}
