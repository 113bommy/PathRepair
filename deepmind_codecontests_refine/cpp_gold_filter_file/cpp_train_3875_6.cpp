#include <bits/stdc++.h>
using namespace std;
struct info {
  int l1, r1, l2, r2;
  info(int _l1, int _r1, int _l2, int _r2) {
    l1 = _l1;
    r1 = _r1;
    l2 = _l2;
    r2 = _r2;
  }
};
const int maxn = 5e5 + 10;
int tree[4 * maxn], lazy[4 * maxn];
vector<pair<int, int> > agrega[maxn], quita[maxn];
vector<pair<int, int> > agrega2[maxn], quita2[maxn];
vector<info> A;
int N;
void build() {
  for (int i = 0; i < 4 * maxn; i++) {
    tree[i] = lazy[i] = 0;
  }
}
void update(int node, int start, int end, int l, int r, int val) {
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start > end || start > r || end < l) return;
  if (start >= l && end <= r) {
    tree[node] += val;
    if (start != end) {
      lazy[node * 2] += val;
      lazy[node * 2 + 1] += val;
    }
    return;
  }
  int mid = (start + end) / 2;
  update(node * 2, start, mid, l, r, val);
  update(node * 2 + 1, mid + 1, end, l, r, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int query(int node, int start, int end, int l, int r) {
  if (start > end || start > r || end < l) return 0;
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  int p1 = query(node * 2, start, mid, l, r);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return max(p1, p2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  vector<int> unicos, diffs;
  ;
  for (int i = 0; i < N; i++) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    unicos.push_back(l1);
    unicos.push_back(r1);
    unicos.push_back(l2);
    unicos.push_back(r2);
    A.push_back(info(l1, r1, l2, r2));
  }
  sort((unicos).begin(), (unicos).end());
  unicos.erase(unique((unicos).begin(), (unicos).end()), unicos.end());
  int fin = 0;
  for (int i = 0; i < N; i++) {
    A[i].l1 =
        lower_bound((unicos).begin(), (unicos).end(), A[i].l1) - unicos.begin();
    A[i].r1 =
        lower_bound((unicos).begin(), (unicos).end(), A[i].r1) - unicos.begin();
    A[i].l2 =
        lower_bound((unicos).begin(), (unicos).end(), A[i].l2) - unicos.begin();
    A[i].r2 =
        lower_bound((unicos).begin(), (unicos).end(), A[i].r2) - unicos.begin();
    fin = max({fin, A[i].l1, A[i].r1, A[i].l2, A[i].r2});
    diffs.push_back(A[i].l1);
    diffs.push_back(A[i].r1);
    diffs.push_back(A[i].l2);
    diffs.push_back(A[i].r2);
    agrega[A[i].l1].push_back({A[i].l2, A[i].r2});
    quita[A[i].r1 + 1].push_back({A[i].l2, A[i].r2});
    agrega2[A[i].l2].push_back({A[i].l1, A[i].r1});
    quita2[A[i].r2 + 1].push_back({A[i].l1, A[i].r1});
  }
  sort((diffs).begin(), (diffs).end());
  diffs.erase(unique((diffs).begin(), (diffs).end()), diffs.end());
  build();
  int cnt = 0;
  fin++;
  for (int i = 0; i < fin + 1; i++) {
    for (auto &x : quita[i]) {
      cnt--;
      update(1, 0, fin, x.first, x.second, -1);
    }
    for (auto &x : agrega[i]) {
      if (cnt) {
        int cntAnt = query(1, 0, fin, x.first, x.second);
        if (cntAnt != cnt) {
          cout << "NO\n";
          ;
          return 0;
        }
      }
      cnt++;
      update(1, 0, fin, x.first, x.second, 1);
    }
  }
  build();
  cnt = 0;
  for (int i = 0; i < fin + 1; i++) {
    for (auto &x : quita2[i]) {
      cnt--;
      update(1, 0, fin, x.first, x.second, -1);
    }
    for (auto &x : agrega2[i]) {
      if (cnt) {
        int cntAnt = query(1, 0, fin, x.first, x.second);
        if (cntAnt != cnt) {
          cout << "NO\n";
          ;
          return 0;
        }
      }
      cnt++;
      update(1, 0, fin, x.first, x.second, 1);
    }
  }
  cout << "YES\n";
  ;
  return 0;
}
