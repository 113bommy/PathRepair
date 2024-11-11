#include <bits/stdc++.h>
const int MAX = 1000010;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-6;
const long double PI = acos(-1.0);
using namespace std;
struct query {
  int x, y, ind;
};
void init(vector<int> &func) {
  for (int i = 0; i <= 100; i++) func.push_back(i);
}
struct Segtree {
  vector<vector<int> > t;
  int n;
  Segtree(int n) {
    this->n = n;
    t.assign(2 * n, vector<int>());
    for (int i = 0; i < 2 * n; i++) init(t[i]);
  }
  void merge(vector<int> &a, vector<int> &b, vector<int> &c) {
    for (int i = 1; i <= 100; i++) c[i] = b[a[i]];
  }
  void update(int p, int x, int y) {
    for (t[p += n][x] = y, p >>= 1; p; p >>= 1)
      merge(t[p << 1], t[p << 1 | 1], t[p]);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a[200010], l, r, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int q;
  cin >> q;
  Segtree st(400000);
  vector<query> sweep[200010];
  for (int i = 0; i < q; i++) {
    cin >> l >> r >> x >> y;
    sweep[l - 1].push_back({x, y, i});
    sweep[r].push_back({x, x, i});
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (auto j : sweep[i]) st.update(j.ind, j.x, j.y);
    vector<int> vet = st.t[1];
    ans.push_back(vet[a[i]]);
  }
  assert((int)ans.size() == n);
  for (auto a : ans) cout << a << " ";
  cout << '\n';
  return 0;
}
