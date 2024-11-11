#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 9;
const int INF = -1;
int values[maxN];
struct edge {
  int l, r;
  int pos;
  int mn;
  int size;
  int val;
  int y;
};
edge v[maxN];
void update(int a) {
  v[a].size = 1;
  if (v[a].l != INF) {
    v[a].size += v[v[a].l].size;
  }
  if (v[a].r != INF) {
    v[a].size += v[v[a].r].size;
  }
  v[a].mn = v[a].val;
  if (v[a].l != INF) {
    v[a].pos = v[a].l;
  } else {
    v[a].pos = 0;
  }
  if (v[a].l != INF) {
    if (v[a].mn >= v[v[a].l].mn) {
      v[a].mn = v[v[a].l].mn;
      v[a].pos = v[v[a].l].pos;
    }
  }
  if (v[a].r != INF) {
    if (v[a].mn > v[v[a].r].mn) {
      v[a].mn = v[v[a].r].mn;
      if (v[a].l != INF) {
        v[a].pos = v[v[a].l].size + 1 + v[v[a].r].pos;
      } else {
        v[a].pos = 1 + v[v[a].r].pos;
      }
    }
  }
}
int merge(int a, int b) {
  if (a == INF) return b;
  if (b == INF) return a;
  if (v[a].y > v[b].y) {
    int c = merge(v[a].r, b);
    v[a].r = c;
    update(a);
    return a;
  } else {
    int c = merge(a, v[b].l);
    v[b].l = c;
    update(b);
    return b;
  }
}
pair<int, int> split(int a, int c) {
  if (a == INF) return make_pair(INF, INF);
  int sz = (v[a].l == INF) ? 0 : v[v[a].l].size;
  if (sz + 1 <= c) {
    auto ans = split(v[a].r, c - sz - 1);
    v[a].r = ans.first;
    update(a);
    return make_pair(a, ans.second);
  } else {
    auto ans = split(v[a].l, c);
    v[a].l = ans.second;
    update(a);
    return make_pair(ans.first, a);
  }
}
int nxt = 0;
int add(int root, int val) {
  int now = nxt++;
  v[now].l = INF;
  v[now].r = INF;
  v[now].val = val;
  v[now].y = rand();
  update(now);
  return merge(root, now);
}
pair<int, int> step(int root) {
  int pos = v[root].pos;
  auto fst = split(root, pos);
  auto snd = split(fst.second, 1);
  return make_pair(merge(snd.second, fst.first), pos + 1);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }
  int root = INF;
  for (int i = 0; i < n; i++) {
    root = add(root, values[i]);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    auto res = step(root);
    root = res.first;
    ans += res.second;
  }
  cout << ans;
  return 0;
}
