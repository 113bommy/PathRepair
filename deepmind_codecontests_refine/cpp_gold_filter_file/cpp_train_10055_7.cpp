#include <bits/stdc++.h>
using namespace std;
vector<int> bb[2500];
int n, m;
int now[200005];
int pos[200005];
int val[200005];
int main() {
  scanf("%d %d", &n, &m);
  const int bloc = ceil(sqrt(n * log2(n)));
  int len = ceil(n * 1.0 / bloc);
  for (int i = 1; i <= n; i++) {
    now[i] = (i - 1) / len + 1;
    bb[now[i]].push_back(i);
    pos[i] = i;
    val[i] = i;
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) swap(a, b);
    int c = val[a], d = val[b];
    ans -= (c > d);
    ans += (c < d);
    for (int i = pos[a] + 1; i <= min(pos[b] - 1, now[a] * len); i++)
      ans -= 2 * (val[i] < c), ans += 2 * (val[i] < d);
    if (now[a] != now[b])
      for (int i = max(pos[a] + 1, (now[b] - 1) * len + 1); i < pos[b]; i++)
        ans += 2 * (val[i] < d), ans -= 2 * (val[i] < c);
    if (a != b)
      for (int i = now[a] + 1; i < now[b]; i++)
        ans -= 2 * (lower_bound(bb[i].begin(), bb[i].end(), c) - bb[i].begin()),
            ans +=
            2 * (lower_bound(bb[i].begin(), bb[i].end(), d) - bb[i].begin());
    bb[now[a]].erase(lower_bound(bb[now[a]].begin(), bb[now[a]].end(), val[a]));
    if (a != b)
      bb[now[b]].erase(
          lower_bound(bb[now[b]].begin(), bb[now[b]].end(), val[b]));
    bb[now[a]].insert(lower_bound(bb[now[a]].begin(), bb[now[a]].end(), val[b]),
                      val[b]);
    if (a != b)
      bb[now[b]].insert(
          lower_bound(bb[now[b]].begin(), bb[now[b]].end(), val[a]), val[a]);
    swap(val[a], val[b]);
    printf("%I64d\n", ans);
  }
  return 0;
}
