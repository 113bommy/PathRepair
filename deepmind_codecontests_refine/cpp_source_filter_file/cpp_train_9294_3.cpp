#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
vector<int> pos[MAXN];
int n;
struct Node {
  int las;
  int ls, rs;
};
struct PerTree {
 public:
  Node t[MAXN * 25];
  int rt[MAXN];
  int tot, n;
  void set(int l, int r) {
    tot = 0;
    n = r;
    build(rt[0], l, r);
  }
  void build(int& p, int l, int r) {
    p = ++tot;
    if (l == r) {
      t[p].las = 0;
      t[p].ls = -1;
      t[p].rs = -1;
      return;
    }
    int mid = (l + r) / 2;
    build(t[p].ls, l, mid);
    build(t[p].rs, mid + 1, r);
    t[p].las = min(t[t[p].ls].las, t[t[p].rs].las);
  }
  void insert(int& p, int q, int l, int r, int a, int pos) {
    p = ++tot;
    t[p] = t[q];
    if (l == r) {
      t[p].las = pos;
      return;
    }
    int mid = (l + r) / 2;
    if (mid >= a)
      insert(t[p].ls, t[q].ls, l, mid, a, pos);
    else
      insert(t[p].rs, t[q].rs, mid + 1, r, a, pos);
    t[p].las = min(t[t[p].ls].las, t[t[p].rs].las);
    return;
  }
  int query(int p, int l, int r, int L) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (t[t[p].ls].las < L)
      return query(t[p].ls, l, mid, L);
    else
      return query(t[p].rs, mid + 1, r, L);
  }
  int Mex(int l, int r) {
    if (l > r) return -1;
    return query(rt[r], 1, n, l);
  }
  void print(int p, int l, int r) {
    if (l == r) {
      cout << l << " : " << t[p].las << endl;
      return;
    }
    int mid = (l + r) / 2;
    print(t[p].ls, l, mid);
    print(t[p].rs, mid + 1, r);
  }
} T;
bool check(int x) {
  int st = 1;
  for (int i = (0); i <= ((int)pos[x].size() - 1); i++) {
    int p = pos[x][i];
    if (T.Mex(st, p - 1) == x) return false;
    st = p + 1;
  }
  if (T.Mex(st, n) == x) return false;
  return true;
}
int main() {
  cin >> n;
  T.set(1, n + 1);
  for (int i = (1); i <= (n); i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
    T.insert(T.rt[i], T.rt[i - 1], 1, n + 1, a[i], i);
  }
  for (int i = (1); i <= (n + 1); i++) {
    if (check(i)) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
