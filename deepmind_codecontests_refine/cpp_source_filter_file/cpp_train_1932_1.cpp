#include <bits/stdc++.h>
using namespace std;
struct st {
  long long cas, noti, val;
};
long long cnt[311111], last[311111];
queue<st> q;
int main() {
  int notif = 0;
  for (long long i = 0; i < 311111; i++) {
    last[i] = -1;
    cnt[i] = 0;
  }
  long long n, m, ans = 0;
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= m; i++) {
    long long t, x;
    scanf("%lld%lld", &t, &x);
    if (t == 1) {
      q.push({i, notif, x});
      notif++;
      cnt[x]++;
      ans++;
    }
    if (t == 2) {
      last[x] = i;
      ans -= cnt[x];
      cnt[x] = 0;
    }
    if (t == 3) {
      while (!q.empty() && q.front().noti < x) {
        long long time = q.front().cas;
        long long tren = q.front().val;
        if (last[tren] < time) {
          ans--;
          cnt[x]--;
        }
        q.pop();
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
