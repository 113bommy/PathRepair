#include <bits/stdc++.h>
using namespace std;
int st_size;
vector<int> st;
void modi(int p, int v) {
  for (st[p += st_size / 2] += v; p > 1; p >>= 1)
    st[p >> 1] = st[p] + st[p ^ 1];
}
int sum(int l, int r) {
  int res = 0;
  for (l += st_size / 2, r += st_size / 2; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += st[l++];
    if (r & 1) res += st[--r];
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = a[i];
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++)
      a[i] = (int)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());
    int ts = 0;
    for (; (1 << ts) < n; ts++)
      ;
    ts++;
    st.clear();
    st_size = 1 << ts;
    st.resize(st_size);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += min(sum(0, a[i]), sum(a[i] + 1, n));
      modi(a[i], 1);
    }
    cout << ans << endl;
  }
}
