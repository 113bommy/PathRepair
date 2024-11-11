#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
string s;
int q, cnt = 0, tot = 0, ax[5000001], vis[5000001], num[5000001], SZ;
vector<int> v[5000001], ansp[5000001];
struct query {
  string s1, s2;
  int h1, h2, ans, ansx;
} que[500001];
struct data {
  int num, loc;
} a[5000001];
void Solve1(int x) {
  for (int i = 1; i <= cnt; i++) ax[i] = 1e9;
  int now = 1e9;
  for (int i = tot; i >= 1; i--) {
    if (a[i].num == x) now = a[i].loc;
    ax[a[i].num] = min(ax[a[i].num], now - a[i].loc);
  }
  for (int i = 0; i < v[x].size(); i++) {
    int kx = v[x][i];
    ansp[x].push_back(ax[kx]);
  }
}
void Solve2() {
  for (int i = 1; i <= cnt; i++) ax[i] = -1e9;
  for (int i = 1; i <= tot; i++) {
    ax[a[i].num] = a[i].loc;
    for (int j = 0; j < v[a[i].num].size(); j++) {
      int kx = v[a[i].num][j];
      if (ansp[a[i].num].size() == j)
        ansp[a[i].num].push_back(a[i].loc - ax[kx]);
      else
        ansp[a[i].num][j] = min(ansp[a[i].num][j], a[i].loc - ax[kx]);
    }
  }
}
void work() {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= q; i++) {
    if (que[i].ans == -1) continue;
    que[i].ans = 1e9;
    vis[que[i].h2]++;
  }
  for (int i = 1; i <= cnt; i++) {
    v[i].clear();
    ansp[i].clear();
  }
  for (int i = 1; i <= q; i++) {
    if (que[i].ans == -1) continue;
    if (vis[que[i].h2] > SZ) {
      v[que[i].h2].push_back(que[i].h1);
      num[i] = v[que[i].h2].size() - 1;
    }
  }
  for (int i = 1; i <= cnt; i++)
    if (v[i].size()) Solve1(i);
  for (int i = 1; i <= cnt; i++) {
    v[i].clear();
    ansp[i].clear();
  }
  for (int i = 1; i <= q; i++) {
    if (que[i].ans == -1) continue;
    if (vis[que[i].h2] > SZ) {
      que[i].ans = ansp[que[i].h2][num[i]];
      continue;
    }
    v[que[i].h2].push_back(que[i].h1);
    num[i] = v[que[i].h2].size() - 1;
  }
  Solve2();
  for (int i = 1; i <= q; i++) {
    if (que[i].ans == -1) continue;
    if (vis[que[i].h1] > SZ) continue;
    que[i].ans = ansp[que[i].h2][num[i]];
  }
}
int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    string now = "";
    for (int j = i; j <= min(i + 3, (int)s.length() - 1); j++) {
      now += s[j];
      if (mp.find(now) == mp.end()) mp[now] = ++cnt;
      int px = mp[now];
      a[++tot].num = px;
      a[tot].loc = i;
    }
  }
  scanf("%d", &q);
  SZ = sqrt(q);
  for (int i = 1; i <= q; i++) cin >> que[i].s1 >> que[i].s2;
  for (int i = 1; i <= q; i++) {
    if (mp.find(que[i].s1) == mp.end() || mp.find(que[i].s2) == mp.end()) {
      que[i].ans = -1;
      continue;
    }
    que[i].h1 = mp[que[i].s1];
    que[i].h2 = mp[que[i].s2];
  }
  work();
  for (int i = 1; i <= q; i++) {
    if (que[i].ans == -1)
      que[i].ansx = -1;
    else
      que[i].ansx = max(que[i].ans + que[i].s2.length(), que[i].s1.length());
    que[i].h1 = mp[que[i].s2];
    que[i].h2 = mp[que[i].s1];
  }
  work();
  for (int i = 1; i <= q; i++)
    if (que[i].ans == -1)
      que[i].ansx = -1;
    else {
      int now = max(que[i].ans + que[i].s1.length(), que[i].s2.length());
      que[i].ansx = min(que[i].ansx, now);
    }
  for (int i = 1; i <= q; i++) printf("%d\n", que[i].ansx);
  return 0;
}
