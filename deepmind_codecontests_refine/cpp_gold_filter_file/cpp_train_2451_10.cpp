#include <bits/stdc++.h>
using namespace std;
int n;
struct segment_tree {
  long long val;
  long long v[100010 << 2], mx[100010 << 2], mn[100010 << 2], addv[100010 << 2],
      setv[100010 << 2];
  void push(int id) {
    mx[id] = max(mx[(id << 1)], mx[(id << 1 | 1)]);
    mn[id] = min(mn[(id << 1)], mn[(id << 1 | 1)]);
  }
  void build(int id, int l, int r) {
    if (l == r) {
      if (v[l] > val) {
        mx[id] = -(1LL << 60), mn[id] = (1LL << 60);
        return;
      }
      mx[id] = mn[id] = v[l];
      return;
    }
    int mid = (l + r) >> 1;
    build((id << 1), l, mid);
    build((id << 1 | 1), mid + 1, r);
    push(id);
  }
  void down(int id) {
    if (setv[id]) {
      if (setv[id] > val) {
        mx[(id << 1)] = mx[(id << 1 | 1)] = -(1LL << 60);
        mn[(id << 1)] = mn[(id << 1 | 1)] = (1LL << 60);
      } else {
        mx[(id << 1)] = mn[(id << 1)] = mx[(id << 1 | 1)] = mn[(id << 1 | 1)] =
            setv[id];
      }
      setv[(id << 1)] = setv[(id << 1 | 1)] = setv[id];
      addv[(id << 1)] = addv[(id << 1 | 1)] = 0;
      setv[id] = 0;
    }
    if (addv[id]) {
      if (mx[(id << 1)] != -(1LL << 60)) {
        mx[(id << 1)] += addv[id], mn[(id << 1)] += addv[id];
        if (mn[(id << 1)] > val) {
          mx[(id << 1)] = -(1LL << 60), mn[(id << 1)] = (1LL << 60);
        }
      }
      if (mx[(id << 1 | 1)] != -(1LL << 60)) {
        mx[(id << 1 | 1)] += addv[id], mn[(id << 1 | 1)] += addv[id];
        if (mn[(id << 1 | 1)] > val) {
          mx[(id << 1 | 1)] = -(1LL << 60), mn[(id << 1 | 1)] = (1LL << 60);
        }
      }
      addv[(id << 1)] += addv[id];
      addv[(id << 1 | 1)] += addv[id];
      addv[id] = 0;
    }
  }
  int updateAdd(int id, int l, int r, int st, int en, int x) {
    if (st <= l && r <= en) {
      if (mx[id] == -(1LL << 60)) return 0;
      if (l == r) {
        mx[id] += x;
        mn[id] += x;
        if (mx[id] == val)
          return 1;
        else if (mx[id] > val) {
          mx[id] = -(1LL << 60);
          mn[id] = (1LL << 60);
        }
        return 0;
      }
      if (mx[id] + x <= val) {
        mx[id] += x, mn[id] += x;
        addv[id] += x;
        return (mx[id] == val);
      }
      if (mn[id] + x > val) {
        mx[id] = -(1LL << 60), mn[id] = (1LL << 60);
        addv[id] += x;
        return 0;
      }
    }
    down(id);
    int mid = (l + r) >> 1;
    int t = 0;
    if (st <= mid) {
      t |= updateAdd((id << 1), l, mid, st, en, x);
    }
    if (mid < en) {
      t |= updateAdd((id << 1 | 1), mid + 1, r, st, en, x);
    }
    push(id);
    return t;
  }
  void updateSet(int id, int l, int r, int st, int en, int x) {
    if (st <= l && r <= en) {
      if (x > val) {
        mx[id] = -(1LL << 60), mn[id] = (1LL << 60);
      } else
        mx[id] = mn[id] = x;
      setv[id] = x;
      addv[id] = 0;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    if (st <= mid) updateSet((id << 1), l, mid, st, en, x);
    if (mid < en) updateSet((id << 1 | 1), mid + 1, r, st, en, x);
    push(id);
  }
  long long calc(int id, int l, int r, int x) {
    if (l == r) return mx[id];
    down(id);
    int mid = (l + r) >> 1;
    if (x <= mid) {
      return calc((id << 1), l, mid, x);
    } else
      return calc((id << 1 | 1), mid + 1, r, x);
    push(id);
  }
} tr[10];
int main() {
  long long tp = 1;
  for (int i = 1; i <= 9; i++) tp *= 42, tr[i].val = tp;
  int type, x, y, z, Q;
  scanf("%d %d", &n, &Q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    for (int j = 1; j <= 9; j++) tr[j].v[i] = x;
  }
  for (int j = 1; j <= 9; j++) tr[j].build(1, 1, n);
  while (Q--) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &x);
      printf("%I64d\n", tr[9].calc(1, 1, n, x));
    } else if (type == 3) {
      scanf("%d %d %d", &x, &y, &z);
      int bf = 1;
      while (bf) {
        bf = 0;
        for (int i = 1; i <= 9; i++) {
          bf |= tr[i].updateAdd(1, 1, n, x, y, z);
        }
      }
    } else {
      scanf("%d %d %d", &x, &y, &z);
      for (int i = 1; i <= 9; i++) tr[i].updateSet(1, 1, n, x, y, z);
    }
  }
}
