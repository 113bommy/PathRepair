#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool uin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const long long inf = 1e18 + 100500;
struct rsq {
  rsq() : l(nullptr), r(nullptr), s(0) {}
  rsq(rsq* l, rsq* r, int s) : l(l), r(r), s(s) {}
  rsq *l, *r;
  int s;
};
int cmake = 0;
rsq* make() {
  cmake++;
  return new rsq();
}
int sum(rsq* r) { return r == nullptr ? 0 : r->s; };
rsq* add(rsq* node, int l, int r, int pos) {
  if (pos < l) return node;
  if (pos >= r) return node;
  rsq* ans = make();
  if (pos == l && pos + 1 == r) {
    ans->l = ans->r = nullptr;
    ans->s = sum(node) + 1;
    return ans;
  }
  int m = (l + r) / 2;
  ans->l = add(node == nullptr ? nullptr : node->l, l, m, pos);
  ans->r = add(node == nullptr ? nullptr : node->r, m, r, pos);
  ans->s = sum(ans->l) + sum(ans->r);
  return ans;
}
int sum(rsq* node, int l, int r, int L, int R) {
  if (!node) return 0;
  if (L >= r || l >= R) return 0;
  uax(L, l);
  uin(R, r);
  if (L == l && r == R) {
    return node->s;
  }
  int m = (l + r) / 2;
  int ans = sum(node->l, l, m, L, R) + sum(node->r, m, r, L, R);
  return ans;
}
int cdown = 0;
int down(rsq* root, int l, int r, int k) {
  cdown += 1;
  if (l + 1 == r) return l;
  if (sum(root) < k) return l - 1;
  if (sum(root->r) >= k) return down(root->r, (l + r) / 2, r, k);
  return down(root->l, l, (l + r) / 2, k - sum(root->r));
}
void solve() {
  int n = 100000;
  cin >> n;
  int lgn = 1;
  while ((1 << lgn) < n) ++lgn;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<vector<int> > pn(n + 1, vector<int>());
  vector<int> next(n, n);
  {
    vector<int> last(n, n);
    for (int i = (int)(n)-1; i >= 0; --i) {
      next[i] = last[a[i]];
      pn[last[a[i]]].push_back(i);
      last[a[i]] = i;
    }
  }
  vector<rsq*> roots(n + 1, nullptr);
  for (int i = (int)(n)-1; i >= 0; --i) {
    rsq* root = roots[i + 1];
    for (int x : pn[i + 1]) {
      root = add(root, 0, n, x);
    }
    roots[i] = root;
  }
  assert(2 * n * lgn >= cmake);
  for (int k = (int)(1); k <= (int)(n); ++k) {
    assert(2 * n * lgn * lgn >= cdown);
    int r = n - 1, ans = 0;
    if (n == 1)
      ans = 1;
    else
      while (r >= 0) {
        r = down(roots[r], 0, n, k + 1 + (n - 1 - r));
        ans += 1;
      }
    cout << ans << " \n"[k == n];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed;
  cout.precision(15);
  cerr << fixed;
  cerr.precision(15);
  solve();
  return 0;
}
