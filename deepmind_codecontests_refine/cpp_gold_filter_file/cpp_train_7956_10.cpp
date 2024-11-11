#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
const int mar = 1000001;
int tree[mar], used[mar], now[mar], seg[mar * 8];
int place[mar], ans[mar];
int times[mar];
int n, x, y, m;
void insert(int k, int x) {
  while (k <= m) {
    tree[k] += x;
    k += k & -k;
  }
}
int query(int k) {
  int ret = 0;
  while (k) {
    ret += tree[k];
    k -= k & -k;
  }
  return ret;
}
void insert(int k, int l, int r, int x, int p) {
  if (l == r) {
    seg[k] = p;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    insert(k * 2, l, mid, x, p);
  else
    insert(k * 2 + 1, mid + 1, r, x, p);
  seg[k] = seg[k * 2] + seg[k * 2 + 1];
}
int query(int k, int l, int r, int p) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (seg[k * 2] >= p)
    return query(k * 2, l, mid, p);
  else
    return query(k * 2 + 1, mid + 1, r, p - seg[k * 2]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    insert(1, 1, n, i, 1);
    place[i] = -1;
    now[i] = -1;
  }
  int cnt = 0;
  for (int __i = 1; __i <= m; __i++) {
    scanf("%d%d", &x, &y);
    if (y <= cnt && now[x] == -1) {
      puts("-1");
      return 0;
    }
    if (y <= cnt) {
      int xx = query(now[x]);
      if (cnt - xx + 1 != y) {
        puts("-1");
        return 0;
      }
      insert(now[x], -1);
      insert(__i, 1);
      now[x] = __i;
    } else {
      if (place[x] > 0) {
        puts("-1");
        return 0;
      }
      int xx = query(1, 1, n, y - cnt);
      place[x] = xx;
      insert(1, 1, n, xx, 0);
      insert(__i, 1);
      now[x] = __i;
      times[y]++;
      cnt++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (place[i] > 0) ans[place[i]] = i;
  int tem = 1;
  for (int i = 1; i <= n; i++)
    if (ans[i] == 0) {
      while (place[tem] != -1) tem++;
      ans[i] = tem++;
    }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  puts("");
  fclose(stdin);
  return 0;
}
