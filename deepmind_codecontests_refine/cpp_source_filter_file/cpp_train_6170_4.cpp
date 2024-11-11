#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const int K = 500;
const int NN = N + 13;
const int KK = K + 13;
int n;
char s[NN];
int k, L, R;
int cs[KK], lfs[KK], rgs[KK];
vector<int> occ[26 + 3];
int cntGood, okRules[N];
int ptr[26];
void dec(char c, int rg) {
  if (ptr[int(c)] < rg) return;
  int lfidx = (ptr[int(c)] - rg - 1 >= 0 ? occ[c][ptr[int(c)] - rg - 1] : -1);
  int rgidx = occ[c][ptr[int(c)] - rg] - (rg == 0);
  for (int i = lfidx + 1; i <= rgidx; i++) {
    okRules[i]--;
    if (okRules[i] == R)
      cntGood++;
    else if (okRules[i] == L - 1)
      cntGood--;
  }
}
void inc(char c, int lf) {
  if (lf == 0) return;
  if (ptr[int(c)] + 1 < lf) return;
  int lfidx = (ptr[int(c)] - lf >= 0 ? occ[c][ptr[int(c)] - lf] : -1);
  int rgidx = occ[c][ptr[int(c)] - lf + 1] - (lf == 1);
  for (int i = lfidx + 1; i <= rgidx; i++) {
    okRules[i]++;
    if (okRules[i] == L)
      cntGood++;
    else if (okRules[i] == R + 1)
      cntGood--;
  }
}
void solve() {
  char tt[10];
  scanf("%s", s);
  n = strlen(s);
  assert(0 < n && n <= N);
  int i, j;
  for (i = 0; i < n; i++) {
    assert(islower(s[i]));
    s[i] -= 'a';
  }
  for (i = 0; i < n; i++) occ[int(s[i])].push_back(i);
  scanf("%d%d%d", &k, &L, &R);
  assert(0 <= L && L <= R && R <= k && k <= K);
  for (i = 0; i < k; i++) {
    scanf("%s", tt);
    cs[i] = tt[0];
    scanf("%d%d", &lfs[i], &rgs[i]);
    assert(islower(cs[i]));
    assert(0 <= lfs[i] && lfs[i] <= rgs[i] && rgs[i] <= n);
    cs[i] -= 'a';
  }
  long long ans = 0;
  memset(ptr, -1, sizeof(ptr));
  for (i = 0; i < n; i++) {
    char curc = s[i];
    ptr[int(curc)]++;
    for (j = 0; j < k; j++)
      if ((curc == cs[j] && lfs[j] == 1 && 1 == rgs[j]) ||
          (curc != cs[j] && lfs[j] == 0))
        okRules[i]++;
    if (L <= okRules[i] && okRules[i] <= R) cntGood++;
    for (j = 0; j < k; j++) {
      if (curc != cs[j]) continue;
      inc(curc, lfs[j]);
      dec(curc, rgs[j]);
    }
    ans += cntGood;
  }
  printf("%lld\n", ans);
}
int main() {
  solve();
  return 0;
}
