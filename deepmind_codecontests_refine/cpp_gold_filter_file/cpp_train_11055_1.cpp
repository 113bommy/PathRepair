#include <bits/stdc++.h>
using namespace std;
int n, m, c, c0, t, minn[500005 << 2], res[500005 << 2], maxx[500005 << 2],
    tag[500005 << 2], pos[500005 << 2], posa[500005 << 2];
long long ans;
struct node {
  int t, a, c;
} a[500005];
vector<int> vec;
priority_queue<pair<int, int> > q[500005];
inline int read() {
  int ans = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    ans = (ans << 1) + (ans << 3) + (c ^ 48), c = getchar();
  return ans * f;
}
inline void print(long long x) {
  if (!x) {
    putchar('0');
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  int tmp[20], top = 0;
  while (x) tmp[++top] = x % 10 + '0', x /= 10;
  while (top) putchar(tmp[top--]);
}
inline void maintain(int x) {
  if (q[posa[(x << 1 | 1)]].empty() ||
      (!q[posa[(x << 1)]].empty() &&
       q[posa[(x << 1)]].top().first >= q[posa[(x << 1 | 1)]].top().first))
    posa[x] = posa[(x << 1)];
  else
    posa[x] = posa[(x << 1 | 1)];
}
void build(int x, int l, int r) {
  if (l == r) {
    posa[x] = l;
    return;
  }
  int mid = l + r >> 1;
  build((x << 1), l, mid);
  build((x << 1 | 1), mid + 1, r);
  maintain(x);
}
void modify(int x, int l, int r, int num) {
  if (l == r) return;
  int mid = l + r >> 1;
  if (num <= mid)
    modify((x << 1), l, mid, num);
  else
    modify((x << 1 | 1), mid + 1, r, num);
  maintain(x);
}
int query(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return posa[x];
  int ans = 0, mid = l + r >> 1;
  if (L <= mid) {
    int tmp = query((x << 1), l, mid, L, R);
    if (q[ans].empty() ||
        (!q[tmp].empty() && q[tmp].top().first > q[ans].top().first))
      ans = tmp;
  }
  if (R > mid) {
    int tmp = query((x << 1 | 1), mid + 1, r, L, R);
    if (q[ans].empty() ||
        (!q[tmp].empty() && q[tmp].top().first > q[ans].top().first))
      ans = tmp;
  }
  return ans;
}
inline void maintain1(int x) {
  if (maxx[(x << 1)] > maxx[(x << 1 | 1)])
    pos[x] = pos[(x << 1)];
  else
    pos[x] = pos[(x << 1 | 1)];
  maxx[x] = max(maxx[(x << 1)], maxx[(x << 1 | 1)]);
  minn[x] = min(minn[(x << 1)], minn[(x << 1 | 1)]);
}
inline void pushdown(int x) {
  if (!tag[x]) return;
  maxx[(x << 1)] += tag[x];
  minn[(x << 1)] += tag[x];
  maxx[(x << 1 | 1)] += tag[x];
  minn[(x << 1 | 1)] += tag[x];
  tag[(x << 1)] += tag[x];
  tag[(x << 1 | 1)] += tag[x];
  tag[x] = 0;
}
void update(int x, int l, int r, int num, int val) {
  if (l == r) {
    minn[x] = maxx[x] = val;
    pos[x] = l;
    return;
  }
  pushdown(x);
  int mid = l + r >> 1;
  if (num <= mid)
    update((x << 1), l, mid, num, val);
  else
    update((x << 1 | 1), mid + 1, r, num, val);
  maintain1(x);
}
pair<int, int> ask(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return make_pair(maxx[x], pos[x]);
  pushdown(x);
  int mid = l + r >> 1;
  pair<int, int> ans = make_pair(0, 0);
  if (L <= mid) {
    pair<int, int> tmp = ask((x << 1), l, mid, L, R);
    ans = max(ans, tmp);
  }
  if (R > mid) {
    pair<int, int> tmp = ask((x << 1 | 1), mid + 1, r, L, R);
    ans = max(ans, tmp);
  }
  maintain1(x);
  return ans;
}
void add(int x, int l, int r, int L, int R, int val) {
  if (L <= l && r <= R) {
    maxx[x] += val;
    minn[x] += val;
    tag[x] += val;
    return;
  }
  pushdown(x);
  int mid = l + r >> 1;
  if (L <= mid) add((x << 1), l, mid, L, R, val);
  if (R > mid) add((x << 1 | 1), mid + 1, r, L, R, val);
  maintain1(x);
}
int main() {
  t = read();
  while (t--) {
    n = read(), m = read(), c = read(), c0 = read();
    vec.clear();
    for (int i = 1; i <= n; ++i)
      a[i].t = read(), a[i].a = read(), a[i].c = read(), vec.push_back(a[i].t);
    vec.push_back(0);
    vec.push_back(m - 1);
    sort(vec.begin(), vec.end());
    int tot = unique(vec.begin(), vec.end()) - vec.begin();
    while (vec.size() > tot) vec.pop_back();
    for (int i = 1; i <= tot * 4; ++i)
      tag[i] = maxx[i] = 0, minn[i] = 0x3f3f3f3f;
    for (int i = 1; i <= n + 2; ++i)
      while (!q[i].empty()) q[i].pop();
    for (int i = 1; i <= n; ++i) {
      int t = lower_bound(vec.begin(), vec.end(), a[i].t) - vec.begin() + 1;
      q[t].push(make_pair(-a[i].c, a[i].a));
    }
    build(1, 1, tot);
    int lst = 1;
    bool flag = 1;
    ans = 0;
    for (int i = 1; i <= tot; ++i) {
      c0 -= (vec[i - 1] - vec[max(0, i - 2)]);
      update(1, 1, tot, i, c0);
      while (minn[1] < 1) {
        pair<int, int> t = ask(1, 1, tot, lst, i - (minn[1] < 0));
        while (t.first == c)
          lst = t.second + 1, t = ask(1, 1, tot, lst, i - (minn[1] < 0));
        if (lst > i - (minn[1] < 0)) {
          flag = 0;
          break;
        }
        int now = query(1, 1, tot, lst, i - (minn[1] < 0));
        if (q[now].empty()) {
          flag = 0;
          break;
        }
        t = ask(1, 1, tot, now, i - (minn[1] < 0));
        int cur = min(q[now].top().second, c - t.first);
        cur = min(cur, (minn[1] < 0 ? 0 : 1) - minn[1]);
        if (!cur) {
          flag = 0;
          break;
        }
        ans += (long long)cur * q[now].top().first;
        pair<int, int> tmp = q[now].top();
        tmp.second -= cur;
        q[now].pop();
        if (tmp.second)
          q[now].push(tmp);
        else
          modify(1, 1, tot, now);
        add(1, 1, tot, now, i, cur);
        c0 += cur;
      }
      if (!flag) break;
    }
    if (flag)
      print(-ans), puts("");
    else
      puts("-1");
  }
}
