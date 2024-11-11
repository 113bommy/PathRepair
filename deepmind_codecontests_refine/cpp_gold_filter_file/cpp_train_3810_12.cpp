#include <bits/stdc++.h>
using namespace std;
const int N = 4e5;
const int inf = 2e9;
vector<int> ele;
int tree[4 * N + 100], idx[N + 100], L[N + 100], R[N + 100], x[N + 100];
int n, k, b[N + 100], lazy[4 * N + 100];
pair<int, int> tree2[400100];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    int cur = ele[tl - 1];
    cur = cur % n;
    if (cur == 0) cur = n;
    tree[v] = b[cur];
  } else {
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
  }
}
void push(int v) {
  if (lazy[v]) {
    lazy[v * 2] = lazy[v * 2 + 1] = lazy[v];
    tree[v * 2] = tree[v * 2 + 1] = lazy[v];
    lazy[v] = 0;
  }
}
void update(int v, int tl, int tr, int l, int r, int val) {
  if (l > r) return;
  if (tl == l && tr == r) {
    lazy[v] = val;
    tree[v] = val;
    return;
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
  }
}
int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return inf;
  if (tl == l && tr == r) {
    return tree[v];
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(r, tm)),
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
}
void build2(int v, int tl, int tr) {
  if (tl == tr) {
    tree2[v] = make_pair(b[tl], tl);
  } else {
    int tm = (tl + tr) / 2;
    build2(v * 2, tl, tm);
    build2(v * 2 + 1, tm + 1, tr);
    tree2[v] = min(tree2[v * 2], tree2[v * 2 + 1]);
  }
}
pair<int, int> getmin(int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return make_pair(inf, inf);
  }
  if (tl == l && tr == r) {
    return tree2[v];
  }
  int tm = (tl + tr) / 2;
  return min(getmin(v * 2, tl, tm, l, min(r, tm)),
             getmin(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", idx + i);
    if (idx[i] == 1) {
      scanf("%d%d%d", L + i, R + i, x + i);
    } else {
      scanf("%d%d", L + i, R + i);
    }
    ele.push_back(L[i]);
    ele.push_back(R[i]);
  }
  ele.push_back(1);
  ele.push_back(n * k);
  sort(ele.begin(), ele.end());
  int m = unique(ele.begin(), ele.end()) - ele.begin();
  int sz = ele.size();
  sz--;
  while (sz >= m) {
    ele.pop_back();
    sz--;
  }
  build2(1, 1, n);
  for (int i = 1; i < m; i++) {
    if (ele[i] - 1 == ele[i - 1]) {
      continue;
    }
    int t1 = ele[i - 1] % n;
    int t2 = ele[i] % n;
    if (t1 == 0) {
      t1 = n;
    }
    if (t2 == 0) {
      t2 = n;
    }
    int dist = ele[i] - ele[i - 1];
    if (dist > n) {
      int t3 = tree2[1].second;
      if (t3 > t1) {
        ele.push_back(ele[i - 1] + t3 - t1);
      } else {
        ele.push_back(ele[i] - (t2 - t3));
      }
    } else if (t1 < t2) {
      pair<int, int> cur = getmin(1, 1, n, t1 + 1, t2 - 1);
      ele.push_back(cur.second - t1 + ele[i - 1]);
    } else if (t1 > t2) {
      pair<int, int> cur =
          min(getmin(1, 1, n, t1 + 1, n), getmin(1, 1, n, 1, t2 - 1));
      ele.push_back(ele[i - 1] + (cur.second - t1 + n) % n);
    }
  }
  m = ele.size();
  sort(ele.begin(), ele.end());
  build(1, 1, m);
  for (int i = 1; i <= q; i++) {
    if (idx[i] == 1) {
      int t1 = lower_bound(ele.begin(), ele.begin() + m, L[i]) - ele.begin();
      int t2 = lower_bound(ele.begin(), ele.begin() + m, R[i]) - ele.begin();
      t1++;
      t2++;
      update(1, 1, m, t1, t2, x[i]);
    } else {
      int t1 = lower_bound(ele.begin(), ele.begin() + m, L[i]) - ele.begin();
      int t2 = lower_bound(ele.begin(), ele.begin() + m, R[i]) - ele.begin();
      t1++;
      t2++;
      printf("%d\n", query(1, 1, m, t1, t2));
    }
  }
}
