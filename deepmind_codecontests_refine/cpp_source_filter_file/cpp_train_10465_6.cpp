#include <bits/stdc++.h>
using namespace std;
namespace TYC {
const int N = 3005;
int n, m, num, k, pre[N], nxt[N], cnt[N];
vector<int> Pos[N];
void work() {
  scanf("%d%d%d%d", &n, &m, &num, &k);
  for (int i = 1, x, y; i <= num; i++) {
    scanf("%d%d", &x, &y);
    Pos[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) sort(Pos[i].begin(), Pos[i].end());
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    memset(cnt, 0, sizeof(int[m + 1]));
    for (int j = i; j <= n; j++)
      for (int p : Pos[j]) cnt[p]++;
    int last = 0;
    for (int j = 1; j <= m; j++)
      if (cnt[j]) {
        pre[j] = last;
        nxt[last] = j;
        last = j;
      }
    nxt[last] = m + 1;
    int tot = 0;
    for (int l = 1, r = nxt[0], sum = 0; r <= m; r = nxt[r]) {
      sum += cnt[r];
      while (sum - cnt[l] >= k) sum -= cnt[l], l = nxt[l];
      if (sum >= k) tot += (nxt[r] - r) * l;
    }
    for (int j = n; j >= i; j--) {
      ans += tot;
      for (int p : Pos[j]) {
        int l = p, r = p, sum = 0;
        while (pre[l] && sum < k) sum += cnt[l = pre[l]];
        for (; r <= m; r = nxt[r]) {
          sum += cnt[r];
          while (sum > k) sum -= cnt[l], l = nxt[l];
          if (l > p) break;
          if (sum == k) tot -= (nxt[r] - r) * (l - pre[l]);
        }
        if (!--cnt[p]) {
          pre[nxt[p]] = pre[p];
          nxt[pre[p]] = nxt[p];
        }
      }
    }
  }
  printf("%lld\n", ans);
}
}  // namespace TYC
int main() {
  TYC::work();
  return 0;
}
