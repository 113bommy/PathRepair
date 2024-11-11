#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, a[N], b[N], c[N], x, y, ptr[3], cur[3];
inline int myrand() { return rand() ^ (rand() << 15); }
struct item {
  item *l, *r;
  int key, prior, cnt;
  long long sum;
  item() {}
  item(int x) {
    key = sum = x;
    prior = myrand();
    cnt = 1;
    l = r = nullptr;
  }
};
typedef item *pitem;
pitem q0, q1, q2, q3;
inline long long sum(pitem v) { return v ? v->sum : 0; }
inline int cnt(pitem v) { return v ? v->cnt : 0; }
inline void upd_cnt(pitem v) {
  if (v) {
    v->sum = sum(v->l) + v->key + sum(v->r);
    v->cnt = cnt(v->l) + 1 + cnt(v->r);
  }
}
void Merge(pitem &v, pitem l, pitem r) {
  if (!l || !r) {
    v = l ? l : r;
    return;
  }
  if (l->prior > r->prior) {
    Merge(l->r, l->r, r);
    v = l;
  } else {
    Merge(r->l, l, r->l);
    v = r;
  }
  upd_cnt(v);
}
void Split(pitem v, int key, pitem &l, pitem &r) {
  if (!v) {
    l = r = nullptr;
    return;
  }
  if (key < v->key) {
    Split(v->l, key, l, v->l);
    r = v;
  } else {
    Split(v->r, key, v->r, r);
    l = v;
  }
  upd_cnt(v);
}
void Splits(pitem v, int key, pitem &l, pitem &r, int add = 0) {
  if (!v) {
    l = r = nullptr;
    return;
  }
  int curkey = cnt(v->l) + add;
  if (key <= curkey) {
    Splits(v->l, key, l, v->l, add);
    r = v;
  } else {
    Splits(v->r, key, v->r, r, add + 1 + cnt(v->l));
    l = v;
  }
  upd_cnt(v);
}
inline void Insert(pitem &v, int key) {
  pitem tr;
  Split(v, key, v, tr);
  Merge(v, v, new item(key));
  Merge(v, v, tr);
}
void Erase(pitem &v, int key) {
  if (v->key == key) {
    Merge(v, v->l, v->r);
  } else {
    Erase(key < v->key ? v->l : v->r, key);
  }
  upd_cnt(v);
}
void Upd(pitem v, int key) {
  if (key <= cnt(v->l)) {
    Upd(v->l, key);
  } else {
    key -= cnt(v->l);
    if (key == 1) {
      Erase(q0, v->key);
      return;
    }
    key -= 1;
    Upd(v->r, key);
  }
}
int main() {
  srand(time(nullptr));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> x;
  for (int i = 1; i <= x; i++) {
    cin >> y;
    if (b[y] > 0) return 1;
    b[y]++;
  }
  cin >> x;
  for (int i = 1; i <= x; i++) {
    cin >> y;
    if (c[y] > 0) return 1;
    c[y]++;
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0 && c[i] == 0) {
      Insert(q0, a[i]);
    } else if (b[i] == 1 && c[i] == 1) {
      Insert(q3, a[i]);
    } else if (c[i] == 1) {
      Insert(q2, a[i]);
      Insert(q0, a[i]);
    } else if (b[i] == 1) {
      Insert(q1, a[i]);
      Insert(q0, a[i]);
    } else {
      assert(false);
    }
  }
  long long ans = 9e18;
  ptr[1] = 1;
  ptr[2] = 1;
  for (int i = m; i >= 0; i--) {
    long long Sum = 0;
    pitem tl, tr;
    Splits(q3, i, q3, tr);
    Sum += sum(q3);
    int x = k - cnt(q3), y = cnt(q3);
    Merge(q3, q3, tr);
    if (cnt(q1) < x || cnt(q2) < x) {
      continue;
    }
    Splits(q1, x, q1, tr);
    Sum += sum(q1);
    y += cnt(q1);
    int sz1 = cnt(q1);
    Merge(q1, q1, tr);
    while (ptr[1] <= sz1) {
      Upd(q1, ptr[1]);
      ptr[1]++;
    }
    Splits(q2, x, q2, tr);
    Sum += sum(q2);
    y += cnt(q2);
    int sz2 = cnt(q2);
    Merge(q2, q2, tr);
    while (ptr[2] <= sz2) {
      Upd(q2, ptr[2]);
      ptr[2]++;
    }
    if (y > m) {
      continue;
    }
    if (m - y > cnt(q0)) {
      continue;
    }
    Splits(q0, m - y, q0, tr);
    Sum += sum(q0);
    Merge(q0, q0, tr);
    ans = min(ans, Sum);
  }
  cout << (ans == 9e18 ? -1 : ans);
}
