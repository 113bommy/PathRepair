#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while ('0' > ch || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n;
struct node {
  int x, y, z, k;
};
vector<node> vis[10000];
queue<pair<int, vector<node> > > q;
signed main() {
  n = read();
  vector<node> tmp;
  node nww;
  nww.k = 1;
  tmp.clear();
  tmp.push_back(nww);
  q.push(make_pair(1, tmp));
  while (!q.empty()) {
    tmp = q.front().second;
    int tmpp = q.front().first;
    q.pop();
    if (tmpp > n || (vis[tmpp].size() && vis[tmpp].size() < tmp.size()))
      continue;
    vis[tmpp] = tmp;
    for (int i = 0; i < tmp.size(); i++) {
      for (int j = 1; j <= 8; j *= 2) {
        int now = tmp[i].k * j;
        node nw;
        nw.x = i;
        nw.y = -1;
        nw.z = j;
        nw.k = now;
        tmp.push_back(nw);
        q.push(make_pair(now, tmp));
        tmp.pop_back();
      }
    }
    for (int i = 0; i < tmp.size(); i++) {
      for (int j = 0; j < tmp.size(); j++) {
        for (int k = 1; k <= 8; k *= 2) {
          int now = tmp[i].k + tmp[j].k * k;
          node nw;
          nw.x = i;
          nw.y = j;
          nw.z = k;
          nw.k = now;
          tmp.push_back(nw);
          q.push(make_pair(now, tmp));
          tmp.pop_back();
        }
      }
    }
  }
  tmp = vis[n];
  printf("%lu\n", tmp.size() - 1);
  for (int i = 1; i < tmp.size(); i++) {
    node nw = tmp[i];
    if (nw.y == -1) {
      printf("lea e%cx, [%d*e%cx]\n", 'a' + nw.x + 1, nw.z, 'a' + nw.x);
    } else {
      printf("lea e%cx, [e%cx + %d*e%cx]\n", 'a' + max(nw.x, nw.y) + 1,
             'a' + nw.x, nw.z, 'a' + nw.y);
    }
  }
  return 0;
}
