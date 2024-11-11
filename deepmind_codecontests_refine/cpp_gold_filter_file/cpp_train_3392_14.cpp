#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int INF = 1e9 + 10;
int n;
long long a[maxn];
int cnt[62];
long long b[maxn], bn;
int R;
bool flag;
int c[maxn], sc[maxn];
int ans[maxn], ansn;
bool Add(long long x) {
  for (int i = 0; i <= 60; i++) {
    if (x == (1LL << i)) {
      cnt[i]++;
      return 1;
    }
  }
  return 0;
}
void init() {
  flag = 1;
  for (int i = 1; i <= 60; i++) {
    while (cnt[i] > cnt[i - 1]) {
      b[++bn] = (1LL << i);
      cnt[i]--;
    }
  }
  for (int i = 60; i >= 1; i--) cnt[i] = cnt[i - 1] - cnt[i];
  cnt[0] = 0;
  sort(b + 1, b + bn + 1);
  R = 0;
  int now = 60;
  for (int i = bn; i >= 1; i--) {
    while (now > 0 && cnt[now] == 0) now--;
    if (now == 0 || (1LL << now) <= b[i]) {
      flag = 0;
      return;
    }
    cnt[now]--;
    R++;
  }
}
bool can(int k, int N) { return sc[k] <= N - k; }
void solve() {
  if (flag == 0) return;
  ansn = 0;
  sc[0] = c[0] = 0;
  int cn = 0;
  for (int i = 1; i <= 60; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      ++cn;
      c[cn] = i;
      sc[cn] = sc[cn - 1] + c[cn];
    }
  }
  int t = 0;
  for (int i = 0; i <= cn; i++) {
    if (can(i, cn)) ans[++ansn] = R + cn - i;
  }
}
int main() {
  while (cin >> n) {
    bn = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      scanf("%I64d", &a[i]);
      if (!Add(a[i])) b[++bn] = a[i];
    }
    init();
    solve();
    if (!flag)
      puts("-1");
    else {
      sort(ans + 1, ans + ansn + 1);
      for (int i = 1; i <= ansn; i++) printf("%d ", ans[i]);
      puts("");
    }
  }
  return 0;
}
