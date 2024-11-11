#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e11;
const int maxn = (int)1e6;
struct segment_tree {
  vector<vector<long long>> st;
  int ts;
  segment_tree() : ts(0) {}
  segment_tree(int n, int k) : ts(1) {
    while (ts < n) ts <<= 1;
    st.resize(2 * ts, vector<long long>(k));
  }
  long long get_f(int l, int r, int L, int R, int j = 0, int v = 1) {
    if (l <= L && R <= r) return st[v][j];
    if (l > R || r < L) return 0;
    return get_f(l, r, L, (L + R) / 2, j, 2 * v) +
           get_f(l, r, (L + R) / 2 + 1, R, j, 2 * v + 1);
  }
  void change_element(int i, int j = 0, long long val = 1) {
    for (i += ts - 1; i >= 1; i /= 2) st[i][j] += val;
  }
};
int power[maxn];
int inverse[maxn];
pair<int, int> c[maxn];
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i].first;
    c[i].second = i;
  }
  sort(c, c + n);
  for (int i = 0; i < n; i++) power[c[i].second] = i + 1;
  segment_tree st(n, 2);
  for (int i = n - 1; i >= 0; i--) {
    inverse[i] = st.get_f(1, power[i] - 1, 1, st.ts);
    st.change_element(power[i]);
    st.change_element(power[i], 1, inverse[i]);
    inverse[i] = st.get_f(1, power[i] - 1, 1, st.ts, 1);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) ans += inverse[i];
  cout << ans;
  return 0;
}
