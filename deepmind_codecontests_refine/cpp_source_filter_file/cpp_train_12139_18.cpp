#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 100 * 1000 + 16;
int const M = 1000 * 1000 * 1000 + 7;
int n, k;
int a[N];
int c[N];
ll e, v[N];
vector<int> idx[N];
struct wavelet {
  int L, R;
  vector<int> b;
  wavelet* l = 0;
  wavelet* r = 0;
  wavelet(int* pl, int* pr, int L, int R) {
    this->L = L;
    this->R = R;
    if (L == R) return;
    int M = L + R >> 1;
    auto f = [M](int x) { return x <= M; };
    b.reserve(pr - pl + 1);
    b.emplace_back(0);
    for (auto p = pl; p != pr; ++p) b.emplace_back(b.back() + f(*p));
    auto pm = stable_partition(pl, pr, f);
    l = new wavelet(pl, pm, L, M);
    r = new wavelet(pm, pr, M + 1, R);
  }
  ~wavelet() {
    delete l;
    delete r;
  }
  int query(int l, int r, int k) {
    if (k < L) return 0;
    if (R <= k) return b[r] - b[l];
    int lf = b[l];
    int rg = b[r];
    return this->l->query(lf, rg, k) + this->r->query(l - lf, r - rg, k);
  }
};
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cin >> n >> k;
  fill_n(a + 1, n, n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    idx[x].emplace_back(i);
    if (++c[x] > k) a[idx[x][c[x] - k - 1]] = i;
  }
  wavelet t(a + 1, a + 1 + n, 1, n + 1);
  int q;
  cin >> q;
  int last = 0;
  while (q--) {
    int xi, yi;
    cin >> xi >> yi;
    int l = (xi + last) % n + 1;
    int r = (yi + last) % n + 1;
    if (l > r) swap(l, r);
    int z = t.query(l - 1, r, r);
    last = r - l + 1 - z;
    cout << last << "\n";
  }
  cout << flush;
}
