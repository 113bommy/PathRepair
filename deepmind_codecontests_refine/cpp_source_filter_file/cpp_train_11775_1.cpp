#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 * 1000 + 100;
int head[MAXN * 2], to[MAXN * 2], nxt[MAXN * 2];
bool vis[MAXN * 2] = {false};
int cnt = 0;
int ans = 0;
void draw(int n);
void add(int l, int r) {
  to[cnt] = r;
  nxt[cnt] = head[l];
  head[l] = cnt++;
}
bool note[MAXN] = {false};
struct message {
  int now;
  int father;
  int deep;
};
struct cmp {
  bool operator()(message l, message r) { return l.deep < r.deep; }
};
priority_queue<message, vector<message>, cmp> pq;
void bfs() {
  queue<pair<int, int>> q;
  int deep = 0;
  q.push({1, deep});
  vis[1] = true;
  while (!q.empty()) {
    auto t = q.front();
    vis[t.first] = true;
    q.pop();
    for (int i = head[t.first]; ~i; i = nxt[i]) {
      if (!vis[to[i]]) {
        q.push({to[i], t.second + 1});
        if (t.second > 1) {
          pq.push({to[i], t.first, t.second + 1});
        }
      }
    }
  }
}
void solve() {
  while (!pq.empty()) {
    auto now = pq.top();
    pq.pop();
    if (!note[now.now]) {
      note[now.father] = true;
      ans++;
      draw(now.father);
    }
  }
}
void draw(int n) {
  for (int i = head[n]; ~i; i = nxt[i]) {
    note[i] = true;
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  memset(head, -1, sizeof(head));
  for (int i = 0; i < n - 1; i++) {
    int l, r;
    cin >> l >> r;
    add(l, r);
    add(r, l);
  }
  bfs();
  solve();
  cout << ans << endl;
}
