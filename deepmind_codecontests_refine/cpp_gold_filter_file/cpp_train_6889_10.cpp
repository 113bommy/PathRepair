#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
const int N = 1e6 + 2;
int n, a[N], w, R[N];
long long it[4 * N];
void upd(int id, int l, int r, int l1, int r1, long long val) {
  if (r1 < l || r < l1) return;
  if (l1 <= l && r <= r1) {
    it[id] += val;
    return;
  }
  int mid = (l + r) / 2;
  upd(2 * id, l, mid, l1, r1, val);
  upd(2 * id + 1, mid + 1, r, l1, r1, val);
}
long long get(int id, int l, int r, int pos) {
  if (pos < l || r < pos) return 0;
  if (l == r) return it[id];
  int mid = (l + r) / 2;
  return it[id] + get(2 * id, l, mid, pos) + get(2 * id + 1, mid + 1, r, pos);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int test = 1;
  while (test--) {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
      int t;
      cin >> t;
      for (int j = 1; j <= t; j++) cin >> a[j];
      a[t + 1] = 0;
      stack<int> st;
      st.push(t + 1);
      R[t + 1] = t + 1;
      for (int j = t; j >= 0; j--) {
        while (!st.empty() && a[st.top()] <= a[j]) st.pop();
        R[j] = (!st.empty()) ? st.top() - 1 : t + 1;
        st.push(j);
      }
      int l = 1;
      for (int j = 0; j <= t + 1; j++) {
        int r = (R[j] == t + 1) ? w : R[j];
        r = min(r, w - t + j);
        if (l <= r) upd(1, 1, w, l, r, (long long)a[j]);
        l = max(l, r + 1);
      }
    }
    for (int i = 1; i <= w; i++) {
      long long res = get(1, 1, w, i);
      cout << res << " ";
    }
    cout << endl;
  }
}
