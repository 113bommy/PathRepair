#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void Open() {}
const int N = 200010;
int sta[N];
struct EVENT {
  int x, y, d;
  bool operator<(const EVENT& o) const { return x < o.x; }
} eve[N];
int cnt[N];
int st[N];
long long ans[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int t = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    sta[t++] = y, sta[t++] = y + m;
    eve[i << 1] = (EVENT){x, y, 1}, eve[i << 1 | 1] = (EVENT){x + m, y, -1};
  }
  sort(sta, sta + t);
  t = unique(sta, sta + t) - sta;
  sort(eve, eve + (n << 1));
  for (int i = 0; i < (n << 1); i++) {
    int y = eve[i].y;
    for (int j = lower_bound(sta, sta + t, y) - sta; sta[j] < y + m; j++) {
      if (cnt[j])
        ans[cnt[j]] += (long long)(sta[j + 1] - sta[j]) * (eve[i].x - st[j]);
      cnt[j] += eve[i].d;
      st[j] = eve[i].x;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d%c", ans[i], " \n"[i == n]);
  }
  return 0;
}
