#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-12;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e3 + 4;
const int maxm = 1e4 + 4;
long long l, r, ans = 0;
int low[19], high[19], f;
void init() {
  for (int i = 0; i < 19; ++i) {
    low[i] = l % 10;
    l /= 10;
  }
  for (int i = 0; i < 19; ++i) {
    high[i] = r % 10;
    r /= 10;
  }
  for (int i = 18; i >= 0; --i)
    if (low[i] != high[i]) {
      f = i;
      break;
    }
}
int cnt[10];
bool check(int pos, bool up, bool down) {
  if (pos == -1) return true;
  if (!up && !down) {
    for (int i = low[pos] + 1; i < high[pos]; ++i)
      if (cnt[i]) return true;
    if (cnt[low[pos]]) {
      cnt[low[pos]]--;
      bool ok = check(pos - 1, 0, 1);
      cnt[low[pos]]++;
      if (ok) return true;
    }
    if (cnt[high[pos]]) {
      cnt[high[pos]]--;
      bool ok = check(pos - 1, 1, 0);
      cnt[high[pos]]++;
      if (ok) return true;
    }
    return false;
  }
  if (down) {
    for (int i = 9; i > low[pos]; --i)
      if (cnt[i]) return true;
    if (cnt[low[pos]]) {
      cnt[low[pos]]--;
      bool ok = check(pos - 1, 0, 1);
      cnt[low[pos]]++;
      if (ok) return true;
    }
    return false;
  }
  if (up) {
    for (int i = 0; i < high[pos]; ++i)
      if (cnt[i]) return true;
    if (cnt[high[pos]]) {
      cnt[high[pos]]--;
      bool ok = check(pos - 1, 1, 0);
      cnt[high[pos]]++;
      if (ok) return true;
    }
    return false;
  }
}
void dfs(int d, int lst) {
  if (d == f + 1) {
    ans += check(f, 0, 0);
    return;
  }
  for (int i = lst; i <= 9; ++i) {
    cnt[i]++;
    dfs(d + 1, i);
    cnt[i]--;
  }
}
int main() {
  int ik, i, j, k, kase;
  scanf("%lld%lld", &l, &r);
  if (l == r) {
    puts("1");
    return 0;
  }
  init();
  dfs(0, 0);
  printf("%lld\n", ans);
  return 0;
}
