#include <bits/stdc++.h>
const int maxtake = 6;
const int solmod = 1000000007;
using namespace std;
int mod, n, mid;
int fuel[10050];
int cnt[125] = {0};
int sol;
bool srec[125];
int an, arr[125];
inline int modit(int x) { return x < mod ? x : x - mod; }
inline int modsol(int x) { return x < solmod ? x : x - solmod; }
void dfs(int x, int way, int taken) {
  if (x > mid || taken >= maxtake) {
    sol = modsol(sol + way);
    return;
  }
  dfs(x + 1, way, taken);
  bool fail = 0;
  for (int i = 0; i < an; i++) {
    int m = modit(arr[i] + x);
    if (srec[m]) {
      fail = 1;
      break;
    }
  }
  if (!fail) {
    for (int i = 0; i < an; i++) {
      int m = modit(arr[i] + x);
      srec[m] = 1;
      arr[an + i] = m;
    }
    an += an;
    dfs(x + 1, way * (long long)cnt[x] % solmod, taken + 1);
    int nn = an >> 1;
    for (int i = nn; i < an; i++) srec[arr[i]] = 0;
    an = nn;
  }
}
int solve() {
  mid = mod / 2;
  for (int i = mid + 1; i < mod; i++) {
    cnt[mod - i] += cnt[i];
    cnt[i] = 0;
  }
  memset(srec, 0, sizeof(srec));
  srec[0] = 1;
  an = 1;
  arr[0] = 0;
  sol = 0;
  dfs(1, 1, 0);
  return sol;
}
int main(void) {
  scanf("%*d %d %d", &mod, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", fuel + i);
    cnt[fuel[i] % mod]++;
  }
  printf("%d\n", solve());
  return 0;
}
