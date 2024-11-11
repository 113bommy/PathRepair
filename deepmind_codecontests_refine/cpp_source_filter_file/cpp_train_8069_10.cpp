#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int prv[maxn], nxt[maxn], cnt[maxn];
int le[maxn];
int r, c, n, k;
vector<int> pos[maxn];
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> r >> c >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    pos[y].emplace_back(x);
  }
  long long res = 0;
  for (int i = 1; i <= 1; ++i) {
    set<int> second;
    second.insert(0);
    second.insert(r + 1);
    for (int j = 0; j <= r; ++j) cnt[j] = 0, le[j] = 0;
    nxt[0] = r + 1;
    prv[r + 1] = 0;
    long long sum = 0;
    for (int j = i; j <= c; ++j) {
      for (int val : pos[j]) {
        if (!cnt[val]) {
          int l = *prev(second.lower_bound(val));
          int r = *(second.upper_bound(val));
          nxt[l] = val;
          nxt[val] = r;
          prv[r] = val;
          prv[val] = l;
          sum -= 1ll * le[l] * (nxt[val] - val);
          second.insert(val);
        }
        cnt[val]++;
        int cur = val, now = 0;
        while (cur != 0) {
          now += cnt[cur];
          if (now >= k) break;
          cur = prv[cur];
        }
        int total = cnt[val];
        if (cur > le[val]) {
          sum += 1ll * (cur - le[val]) * (nxt[val] - val);
          le[val] = cur;
        }
        while (true) {
          val = nxt[val];
          total += cnt[val];
          now += cnt[val];
          if (val > r || total > k) break;
          while (cur < val && now - cnt[cur] >= k) {
            now -= cnt[cur];
            cur = nxt[cur];
          }
          if (cur > le[val]) {
            assert(now >= k);
            sum += 1ll * (cur - le[val]) * (nxt[val] - val);
            le[val] = cur;
          }
        }
      }
      res += sum;
    }
  }
  cout << res;
}
