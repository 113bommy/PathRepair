#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int belong[N], cnt, len;
bool vis[N];
int BLOCK;
char s[N];
vector<int> ans[N];
struct block {
  bool Has[2];
  int id, l, r;
  int fd(int pat) {
    for (int i = l; i <= r; ++i) {
      if (!vis[i] && s[i] - '0' == pat) return i;
    }
    if (pat == 0)
      Has[0] = false;
    else
      Has[1] = false;
    return -1;
  }
} dat[N];
void init() {
  BLOCK = sqrt(len) + 1;
  cnt = len % BLOCK == 0 ? len / BLOCK : len / BLOCK + 1;
  for (int i = 0; i < cnt; ++i) {
    dat[i].l = i * BLOCK;
    dat[i].r = (i + 1) * BLOCK - 1;
  }
  dat[cnt - 1].r = len - 1;
  for (int i = 0; i < len; ++i) {
    belong[i] = i / BLOCK;
  }
  for (int i = 0; i < len; ++i) {
    dat[belong[i]].Has[s[i] - '0'] = true;
  }
  memset(vis, 0, sizeof(vis));
}
int Find(int pos, int pat) {
  int nowb = belong[pos];
  for (int i = pos; i <= dat[nowb].r; ++i) {
    if (s[i] - '0' == pat && !vis[i]) return i;
  }
  nowb++;
  while (nowb < cnt) {
    if (!dat[nowb].Has[pat]) {
      nowb++;
      continue;
    }
    int res = dat[nowb].fd(pat);
    if (res != -1)
      return res;
    else
      nowb++;
  }
  if (nowb == cnt)
    return -1;
  else {
    for (int i = dat[nowb].l; i <= dat[nowb].r; ++i) {
      if (s[i] - '0' == pat && !vis[i]) return i;
    }
  }
  return -1;
}
void solve() {
  int sum = 0, now = 0;
  while (1) {
    int la = Find(0, 0);
    if (la == -1)
      break;
    else
      sum += 1;
    vis[la] = true;
    ans[now].push_back(la);
    while (1) {
      int p1 = Find(la, 1), p2 = Find(max(p1, 0), 0);
      if (p1 == -1 || p2 == -1) {
        ++now;
        break;
      } else {
        vis[p1] = vis[p2] = true;
        ans[now].push_back(p1);
        ans[now].push_back(p2);
        sum += 2;
        la = p2;
      }
    }
  }
  if (sum == len) {
    printf("%d\n", now);
    for (int i = 0; i < now; ++i) {
      printf("%d", ans[i].size());
      for (auto v : ans[i]) {
        printf(" %d", v);
      }
      puts("");
    }
  } else
    printf("-1\n");
}
int main() {
  scanf("%s", s);
  len = strlen(s);
  init();
  solve();
  return 0;
}
