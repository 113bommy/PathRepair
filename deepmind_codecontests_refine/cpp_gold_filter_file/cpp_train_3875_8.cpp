#include <bits/stdc++.h>
using namespace std;
int numx[1000000], numy[1000000], x[1000000], y[1000000];
struct node {
  int l, r, pos;
} a[1000000], b[1000000];
int laze[1000000];
int num1[1000000], laze1[1000000];
bool cmp(node a, node b) { return a.l < b.l || (a.l == b.l && a.r < b.r); }
void pushupy(int rt) { numy[rt] = max(numy[rt * 2], numy[rt * 2 + 1]); }
void pushdown(int l, int r, int rt) {
  if (laze[rt]) {
    int mid = (l + r) / 2;
    laze[rt * 2] += laze[rt];
    laze[rt * 2 + 1] += laze[rt];
    numy[rt * 2] += laze[rt];
    numy[rt * 2 + 1] += laze[rt];
    laze[rt] = 0;
  }
}
void updatay(int l, int r, int ql, int qr, int val, int rt) {
  if (l >= ql && r <= qr) {
    numy[rt] += val;
    laze[rt] += val;
    return;
  }
  pushdown(l, r, rt);
  int mid = (l + r) / 2;
  if (ql <= mid) updatay(l, mid, ql, qr, val, rt * 2);
  if (qr > mid) updatay(mid + 1, r, ql, qr, val, rt * 2 + 1);
  pushupy(rt);
}
void pushup1(int rt) { num1[rt] = max(num1[rt * 2], num1[rt * 2 + 1]); }
void pushdown1(int l, int r, int rt) {
  if (laze1[rt]) {
    int mid = (l + r) / 2;
    laze1[rt * 2] += laze1[rt];
    laze1[rt * 2 + 1] += laze1[rt];
    num1[rt * 2] += laze1[rt];
    num1[rt * 2 + 1] += laze1[rt];
    laze1[rt] = 0;
  }
}
void updata1(int l, int r, int ql, int qr, int val, int rt) {
  if (l >= ql && r <= qr) {
    num1[rt] += val;
    laze1[rt] += val;
    return;
  }
  pushdown1(l, r, rt);
  int mid = (l + r) / 2;
  if (ql <= mid) updata1(l, mid, ql, qr, val, rt * 2);
  if (qr > mid) updata1(mid + 1, r, ql, qr, val, rt * 2 + 1);
  pushup1(rt);
}
set<pair<int, int> > s;
bool get(int a, int b, int c, int d) { return max(a, c) <= min(b, d); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> a[i].l >> a[i].r >> b[i].l >> b[i].r;
    a[i].pos = i;
    b[i].pos = i;
    y[i] = b[i].l;
    y[i + n] = b[i].r;
  }
  if (n <= 5000) {
    int flag = 0;
    for (int i = (0); i < (n); i++) {
      for (int j = (0); j < (n); j++) {
        if (get(a[i].l, a[i].r, a[j].l, a[j].r) !=
            get(b[i].l, b[i].r, b[j].l, b[j].r)) {
          flag = 1;
          break;
        }
      }
    }
    if (flag) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
    return 0;
  }
  sort(y, y + 2 * n);
  int leny = unique(y, y + 2 * n) - y;
  sort(a, a + n, cmp);
  int flag = 0;
  s.insert(make_pair(a[0].r, 0));
  int cnt = 1;
  updatay(1, leny, lower_bound(y, y + leny, b[a[0].pos].l) - y + 1,
          lower_bound(y, y + leny, b[a[0].pos].r) - y + 1, 1, 1);
  updata1(1, leny, lower_bound(y, y + leny, b[a[0].pos].l) - y + 1,
          lower_bound(y, y + leny, b[a[0].pos].r) - y + 1, 1, 1);
  for (int i = (1); i < (n); i++) {
    int nowyl = lower_bound(y, y + leny, b[a[i].pos].l) - y + 1;
    int nowyr = lower_bound(y, y + leny, b[a[i].pos].r) - y + 1;
    vector<pair<int, int> > v;
    for (auto j : s) {
      if (j.first < a[i].l)
        v.push_back(j);
      else
        break;
    }
    for (auto j : v) {
      s.erase(j);
      updatay(1, leny, lower_bound(y, y + leny, b[a[j.second].pos].l) - y + 1,
              lower_bound(y, y + leny, b[a[j.second].pos].r) - y + 1, -1, 1);
      if (numy[1] != s.size()) {
        flag = 1;
      }
    }
    if (flag) break;
    updatay(1, leny, nowyl, nowyr, 1, 1);
    updata1(1, leny, nowyl, nowyr, 1, 1);
    s.insert(make_pair(a[i].r, i));
    cnt = max(cnt, (int)s.size());
    if (numy[1] != s.size()) {
      flag = 1;
      break;
    }
    if (num1[1] != cnt) {
      flag = 1;
      break;
    }
  }
  vector<pair<int, int> > v;
  for (auto j : s) {
    v.push_back(j);
  }
  for (auto j : v) {
    s.erase(j);
    updatay(1, leny, lower_bound(y, y + leny, b[a[j.second].pos].l) - y + 1,
            lower_bound(y, y + leny, b[a[j.second].pos].r) - y + 1, -1, 1);
    if (numy[1] != s.size()) {
      flag = 1;
    }
  }
  if (flag) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
  }
  return 0;
}
