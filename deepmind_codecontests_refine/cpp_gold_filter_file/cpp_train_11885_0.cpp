#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n, m, a, b, cnt[maxn];
vector<pair<int, int> > v;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    v.push_back(make_pair(a, b));
  }
  int now = v[0].first;
  int flag = 0;
  memset(cnt, 0, sizeof(cnt));
  cnt[now] = 1;
  for (int i = 1; i < m; i++) {
    if (v[i].first == now || v[i].second == now) {
      cnt[now]++;
    } else {
      cnt[v[i].first]++;
      cnt[v[i].second]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != now) {
      if (cnt[i] + cnt[now] == m) flag = 1;
    }
  }
  now = v[0].second;
  memset(cnt, 0, sizeof(cnt));
  cnt[now] = 1;
  for (int i = 1; i < m; i++) {
    if (v[i].first == now || v[i].second == now) {
      cnt[now]++;
    } else {
      cnt[v[i].first]++;
      cnt[v[i].second]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != now) {
      if (cnt[i] + cnt[now] == m) flag = 1;
    }
  }
  if (flag == 1)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
