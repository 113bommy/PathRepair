#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
const double error = 1e-8;
const double PI = acos(-1);
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
inline long long int MOD(long long int x, long long int m = mod) {
  long long int y = x % m;
  return (y >= 0) ? y : y + m;
}
const int inf = INT_MAX;
const unsigned long long int infl = 1e18 + 1;
const int nmax = 1e9 + 5;
map<int, int> events;
pair<map<int, int>::iterator, map<int, int>::iterator> getadj(
    map<int, int>::iterator it) {
  auto it2 = it;
  return {--it, ++it2};
}
struct node {
  node *lc, *rc;
  int l, r, mid;
  long long int maxdec, del;
  long long int lazy;
  node(int _l, int _r) {
    l = _l, r = _r;
    mid = (l + r) >> 1;
    lazy = inf;
    lc = rc = NULL;
    del = maxdec = 0;
  }
  void propagate() {
    if (l != r && lc == NULL) lc = new node(l, mid), rc = new node(mid + 1, r);
    if (lazy == inf) return;
    if (l != r) {
      lc->lazy = rc->lazy = lazy;
    }
    del = (r - l + 1) * lazy;
    maxdec = min(0LL, del);
    lazy = inf;
  }
};
double query(node *root, int L, int R, long long int &v) {
  root->propagate();
  if (R < root->l || L > root->r) return -1;
  if (L <= root->l && root->r <= R) {
    if (root->maxdec + v > 0) {
      v += root->del;
      return -1;
    } else if (root->l == root->r)
      return root->l - double(v) / root->del - 1;
  }
  double ret = query(root->lc, L, R, v);
  if (ret == -1) ret = query(root->rc, L, R, v);
  return ret;
}
void update(node *root, int L, int R, long long int s) {
  root->propagate();
  if (root->l > R || root->r < L) return;
  if (L <= root->l && root->r <= R) {
    root->lazy = s;
    root->propagate();
    return;
  }
  update(root->lc, L, R, s);
  update(root->rc, L, R, s);
  root->del = root->lc->del + root->rc->del;
  root->maxdec = min(root->lc->maxdec, root->lc->del + root->rc->maxdec);
  return;
}
int main() {
  events[0] = 0;
  events[nmax] = 0;
  int q;
  scanf("%d", &q);
  node *root = new node(0, nmax);
  for (int i = 0; i < q; i++) {
    int t, l, r;
    long long int v;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d", &l, &r);
      l++;
      auto it = getadj(events.insert({l, r}).first).second;
      update(root, l, it->first - 1, r);
    } else if (t == 2) {
      scanf("%d", &l);
      l++;
      auto it = events.find(l);
      auto p = getadj(it);
      update(root, p.first->first, p.second->first - 1, p.first->second);
      events.erase(it);
    } else {
      scanf("%d %d %lld", &l, &r, &v);
      double V = v;
      auto p = events.upper_bound(l);
      double ans;
      if (v == 0)
        ans = l;
      else if (p->first > r)
        ans = -1;
      else
        ans = query(root, p->first, r, v);
      printf("%.8f\n", ans);
    }
  }
}
