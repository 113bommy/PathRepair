#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
int K[maxn];
bool vis[maxn];
pair<int, int> off[maxn];
int N, M, sum;
vector<int> s[maxn];
bool judge(int x) {
  int m = x;
  int cnt = 0;
  memset((vis), 0, sizeof(vis));
  for (int i = x; i >= 1; i--) {
    m = min(m, i);
    if (i > 2e5 || s[i].size() == 0) continue;
    for (auto t : s[i]) {
      if (!vis[t] && K[t]) {
        int n = min(K[i], min(i, m));
        m -= n;
        cnt += n;
        vis[t] = 1;
      }
    }
  }
  return (sum - cnt) * 2 + cnt <= x;
}
int main() {
  scanf("%d%d", &N, &M);
  int l, r;
  for (int i = 1; i <= N; i++) scanf("%d", &K[i]), sum += K[i];
  for (int i = 1; i <= M; i++) {
    int d, t;
    scanf("%d%d", &d, &t);
    s[d].push_back(t);
  }
  l = sum;
  r = sum * 2;
  while (l < r) {
    int mid = (l + r) / 2;
    if (judge(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
}
