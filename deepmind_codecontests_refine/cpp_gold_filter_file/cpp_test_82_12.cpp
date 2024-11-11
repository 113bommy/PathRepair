#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)3e5 + 5;
vector<pair<int, int>> qqu[MAXN];
vector<array<int, 3>> qu[MAXN];
long long mem[MAXN];
int a[MAXN], b[MAXN];
long long ans[MAXN];
int n, q, k;
namespace Sparse {
const int K = 19;
int t[K][MAXN];
int lg[MAXN];
void build() {
  lg[1] = 0;
  for (int i = 1; i <= n; i++) {
    t[0][i] = a[i];
    if (i > 1) {
      lg[i] = lg[i / 2] + 1;
    }
  }
  for (int i = 1; i < K; i++) {
    int step = (1 << i);
    for (int j = 1; j + step - 1 <= n; j++) {
      t[i][j] = min(t[i - 1][j], t[i - 1][j + step / 2]);
    }
  }
}
int query(int l, int r) {
  int k = lg[r - l + 1];
  return min(t[k][l], t[k][r - (1 << k) + 1]);
}
}  // namespace Sparse
struct FenwickTree {
  vector<long long> t;
  FenwickTree(int n) { t = vector<long long>(n, 0ll); }
  void update(int p, long long x) {
    for (; p < (int)(t).size(); p |= (p + 1)) {
      t[p] += x;
    }
  }
  void update(int l, int r, long long x) {
    update(l, x);
    update(r, -x);
  }
  long long get(int p) {
    long long res = 0;
    for (; p >= 0; --p) {
      res += t[p];
      p &= (p + 1);
    }
    return res;
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    r = l + ((r - l) / k) * k;
    ans[i] += a[l];
    l += k;
    if (l <= r) {
      qu[l % k].push_back({l / k, r / k, i});
    }
  }
  Sparse::build();
  for (int i = k + 1; i <= n; i++) {
    b[i] = Sparse::query(i - k, i);
  }
  for (int rem = 0; rem < k; rem++) {
    vector<int> vec;
    for (int i = rem; i <= n; i += k) {
      vec.push_back(b[i]);
    }
    int m = (int)(vec).size();
    for (int i = 0; i < m; i++) {
      qqu[i].clear();
      mem[i] = 0ll;
    }
    for (auto &&[l, r, idx] : qu[rem]) {
      qqu[l].push_back({r, idx});
    }
    vector<int> st = {m};
    FenwickTree A(m), B(m);
    for (int i = m - 1; ~i; i--) {
      while ((int)(st).size() > 1 && vec[st.back()] >= vec[i]) {
        int l = st.end()[-1];
        int r = st.end()[-2];
        long long delta = vec[l] - vec[i];
        B.update(r, -delta * (r - l));
        B.update(l, r, delta * (l - 1));
        A.update(l, r, -delta);
        st.pop_back();
      }
      B.update(i, vec[i]);
      st.push_back(i);
      for (auto &[r, idx] : qqu[i]) {
        ans[idx] += A.get(r) * r + B.get(r);
        ans[idx] += mem[r];
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
