#include <bits/stdc++.h>
using namespace std;
const int maxn = 400005;
int N, M, sc, flag, diff, rc, flagrc, pre;
int a[maxn], times[maxn], now[maxn];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
  memset(times, 0, sizeof(times));
  scanf("%d", &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d", &sc);
    ++times[sc];
  }
  memset(now, 0, sizeof(now));
  sc = 1, flag = 1;
  long long ttdis = 0;
  now[1] = 1;
  for (int i = 1; i <= M - 1; i++) {
    if ((sc == N) && (flag == 1)) flag = -1;
    if ((sc == 1) && (flag == -1)) flag = 1;
    pre = sc;
    sc += flag;
    now[sc]++;
    ttdis += int(abs(a[pre] - a[sc]));
  }
  diff = 0;
  for (int i = 1; i <= N; i++)
    if (now[i] != times[i]) ++diff;
  rc = 1, flagrc = 1;
  vector<long long> ans;
  ans.clear();
  for (int i = 1; i <= N * 2; i++) {
    if (diff == 0) ans.push_back(ttdis);
    if (now[rc] == times[rc]) ++diff;
    now[rc]--;
    if (now[rc] == times[rc]) --diff;
    if ((rc == N) && (flagrc == 1)) flagrc = -1;
    if ((rc == 1) && (flagrc == -1)) flagrc = 1;
    pre = rc;
    rc += flagrc;
    ttdis -= int(abs(a[pre] - a[rc]));
    if ((sc == N) && (flag == 1)) flag = -1;
    if ((sc == 1) && (flag == -1)) flag = 1;
    pre = sc;
    sc += flag;
    ttdis += int(abs(a[pre] - a[sc]));
    if (now[sc] == times[sc]) ++diff;
    now[sc]++;
    if (now[sc] == times[sc]) --diff;
  }
  sort(ans.begin(), ans.end());
  int rf = 1;
  for (int i = 1; i < ans.size(); i++)
    if (ans[i] != ans[i - 1]) rf = 0;
  if ((rf == 0) || (ans.size() == 0))
    printf("-1\n");
  else
    printf("%I64d\n", ans[0]);
  return 0;
}
