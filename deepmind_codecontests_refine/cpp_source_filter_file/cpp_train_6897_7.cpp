#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  int tim, a, b, id;
  bool operator<(const node& aa) const { return tim < aa.tim; }
} a[N];
deque<node> s[5], rt[5];
int vis[N];
vector<int> ad, de;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &a[i].tim, &a[i].a, &a[i].b), a[i].id = i;
  sort(a + 1, a + 1 + n);
  int na = 0, nb = 0, ans = 2e9;
  for (int i = 1; i <= n; i++) {
    int ne = 0;
    if (a[i].a) ne |= 1;
    if (a[i].b) ne |= 2;
    rt[ne].push_back(a[i]);
  }
  int sum = 0;
  int x = (int)rt[1].size(), y = (int)rt[2].size();
  int mi = min(x, y);
  if ((int)rt[3].size() + min(mi, (m - (int)rt[3].size()) / 2) < k)
    return 0 * printf("-1\n");
  while (s[3].size() + min(mi, (m - (int)s[3].size()) / 2) < k ||
         s[3].size() + rt[1].size() + rt[2].size() + rt[0].size() < m) {
    s[3].push_back(rt[3].front());
    sum += rt[3].front().tim;
    vis[rt[3].front().id] = 1;
    rt[3].pop_front();
  }
  int ned = k - s[3].size();
  for (int i = 1; i <= ned; i++) {
    s[2].push_back(rt[2].front());
    sum += rt[2].front().tim;
    vis[rt[2].front().id] = 1;
    rt[2].pop_front();
    s[1].push_back(rt[1].front());
    sum += rt[1].front().tim;
    vis[rt[1].front().id] = 1;
    rt[1].pop_front();
  }
  int res = m - s[3].size() - max(0, 2 * (k - (int)s[3].size()));
  for (int i = 1; i <= res; i++) {
    int add = -1;
    if (rt[0].size()) add = 0;
    if (rt[1].size() && (add == -1 || rt[add].front().tim > rt[1].front().tim))
      add = 1;
    if (rt[2].size() && (add == -1 || rt[add].front().tim > rt[2].front().tim))
      add = 2;
    s[add].push_back(rt[add].front());
    sum += rt[add].front().tim;
    vis[rt[add].front().id] = 1;
    rt[add].pop_front();
  }
  ans = sum;
  for (; rt[3].size() && s[3].size() < m;) {
    sum = ans;
    ad.clear(), de.clear();
    s[3].push_back(rt[3].front());
    ad.push_back(rt[3].front().id);
    sum += rt[3].front().tim;
    rt[3].pop_front();
    int num = 0;
    if (s[2].size()) {
      rt[2].push_front(s[2].back());
      de.push_back(s[2].back().id);
      sum -= s[2].back().tim;
      s[2].pop_back();
      num++;
    }
    if (s[1].size()) {
      rt[1].push_front(s[1].back());
      de.push_back(s[1].back().id);
      sum -= s[1].back().tim;
      s[1].pop_back();
      num++;
    }
    if (s[0].size()) {
      rt[0].push_front(s[0].back());
      de.push_back(s[0].back().id);
      sum -= s[0].back().tim;
      s[0].pop_back();
      num++;
    }
    while (num > 1) {
      int add = -1;
      if (rt[0].size()) add = 0;
      if (rt[1].size() &&
          (add == -1 || rt[add].front().tim > rt[1].front().tim))
        add = 1;
      if (rt[2].size() &&
          (add == -1 || rt[add].front().tim > rt[2].front().tim))
        add = 2;
      s[add].push_back(rt[add].front());
      sum += rt[add].front().tim;
      ad.push_back(rt[add].front().id);
      rt[add].pop_front();
      num--;
    }
    if (sum < ans) {
      for (int i : ad) vis[i] = 1;
      for (int i : de) vis[i] = 0;
      ans = sum;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (vis[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
