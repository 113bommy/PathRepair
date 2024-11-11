#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
struct node {
  int key, prio, sz;
  int ch[2];
} treap[maxn];
int tot, root;
void rotate(int &rt, bool d) {
  int x = rt;
  rt = treap[rt].ch[!d];
  treap[x].ch[!d] = treap[rt].ch[d];
  treap[rt].ch[d] = x;
  treap[x].sz = treap[treap[x].ch[0]].sz + 1 + treap[treap[x].ch[1]].sz;
  treap[rt].sz = treap[treap[rt].ch[0]].sz + 1 + treap[treap[rt].ch[1]].sz;
}
int randint() {
  static int seed = 703;
  return seed = int(seed * 48271LL % 2147483647);
}
void ins(int &rt, int key) {
  if (!rt) {
    rt = ++tot;
    treap[rt].key = key;
    treap[rt].prio = randint();
    treap[rt].sz = 1;
  } else {
    int d;
    ins(treap[rt].ch[d = key > treap[rt].key], key);
    treap[rt].sz++;
    if (treap[rt].prio < treap[treap[rt].ch[d]].prio) rotate(rt, !d);
  }
}
bool erase(int &rt, int key) {
  if (!rt) return false;
  if (key != treap[rt].key) {
    if (erase(treap[rt].ch[key > treap[rt].key], key)) {
      treap[rt].sz--;
      return true;
    }
    return false;
  } else if (treap[rt].ch[0] == 0)
    rt = treap[rt].ch[1];
  else if (treap[rt].ch[1] == 0)
    rt = treap[rt].ch[0];
  else {
    int &lft = treap[rt].ch[0], &rgt = treap[rt].ch[1];
    bool d = treap[lft].prio > treap[rgt].prio;
    rotate(rt, d);
    erase(treap[rt].ch[d], key);
    treap[rt].sz--;
  }
  return true;
}
void getrank(int rt, int key, int &ans) {
  if (!rt) return;
  int nums = 0;
  if (key > treap[rt].key) {
    ans += treap[treap[rt].ch[0]].sz + 1;
    getrank(treap[rt].ch[1], key, ans);
  } else if (key == treap[rt].key) {
    ans += treap[treap[rt].ch[0]].sz + 1;
  } else {
    getrank(treap[rt].ch[0], key, ans);
  }
}
int X[maxn], R[maxn], Q[maxn];
int n, k;
priority_queue<pair<int, int> > PQ;
int idx = 0;
unordered_map<int, int> mp;
int roots[maxn];
int ss[maxn];
bool comp(int a, int b) { return X[a] < X[b]; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> X[i] >> R[i] >> Q[i];
    if (!mp[Q[i]]) {
      mp[Q[i]] = ++idx;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ss[i] = i;
  }
  sort(ss, ss + n, comp);
  long long ans = 0;
  PQ.push(make_pair(X[ss[n]] - R[ss[n]], ss[n]));
  ins(roots[mp[Q[ss[n]]]], X[ss[n]]);
  for (int i = n - 1; i >= 1; --i) {
    while (!PQ.empty() && PQ.top().first > X[ss[i]]) {
      int id = PQ.top().second;
      erase(roots[mp[Q[id]]], X[id]);
      PQ.pop();
    }
    for (int j = -k; j <= k; ++j) {
      int newIQ = j + Q[ss[i]];
      if (!mp[newIQ]) continue;
      int rk = 0;
      getrank(roots[mp[newIQ]], X[ss[i]] + R[ss[i]], rk);
      ans += rk;
    }
    ins(roots[mp[Q[ss[i]]]], X[ss[i]]);
    PQ.push(make_pair(X[ss[i]] - R[ss[i]], ss[i]));
  }
  cout << ans << endl;
}
