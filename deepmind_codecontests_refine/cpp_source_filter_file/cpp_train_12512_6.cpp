#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
  bool a[26];
  node() {
    for (int i = 0; i < 26; ++i) {
      a[i] = 0;
    }
  }
} st[4 * N], emp;
char s[N];
int n;
int tp, l, r;
char c;
void merge(int rot, int x, int y) {
  for (int i = 0; i < 26; ++i) {
    st[rot].a[i] = st[x].a[i] | st[y].a[i];
  }
}
void bulid(int v, int tl, int tr) {
  if (tl == tr) {
    int x = s[tl] - 'a';
    st[v].a[x] = 1;
    return;
  }
  int tm = (tl + tr) >> 1;
  bulid(2 * v, tl, tm);
  bulid(2 * v + 1, tm + 1, tr);
  merge(v, 2 * v, 2 * v + 1);
}
struct node qr(int v, int tl, int tr, int l, int r) {
  if (tl > r || tr < l || l > r) {
    return emp;
  }
  if (tl == l && tr == r) {
    return st[v];
  }
  int tm = (tl + tr) >> 1;
  struct node lx = qr(2 * v, tl, tm, l, min(r, tm));
  struct node rx = qr(2 * v + 1, tl, tm, max(l, tm + 1), r);
  struct node ret;
  for (int i = 0; i < 26; ++i) {
    ret.a[i] = lx.a[i] | rx.a[i];
  }
  return ret;
}
void pointup(int v, int tl, int tr, int l, char c) {
  if (tl == tr) {
    st[v].a[s[tl] - 'a'] = false;
    st[v].a[c - 'a'] = true;
    s[l] = c;
  } else {
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
      pointup(2 * v, tl, tm, l, c);
    } else {
      pointup(2 * v + 1, tm + 1, tr, l, c);
    }
    merge(v, v + v, v + v + 1);
  }
}
int main() {
  cin >> s;
  n = strlen(s);
  bulid(1, 0, n - 1);
  int q;
  cin >> q;
  while (q--) {
    cin >> tp;
    if (tp == 2) {
      cin >> l >> r;
      struct node rett = qr(1, 0, n - 1, l - 1, r - 1);
      int ot = 0;
      for (int i = 0; i < 26; ++i) {
        ot += rett.a[i] & 1;
      }
      cout << ot << endl;
    } else {
      cin >> l >> c;
      pointup(1, 0, n - 1, l - 1, c);
    }
  }
}
