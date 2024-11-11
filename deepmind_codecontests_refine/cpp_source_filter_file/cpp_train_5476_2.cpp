#include <bits/stdc++.h>
using namespace std;
string s, t, w;
int n, m, x, a[1001], b[1001], y;
set<int> st;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 1; i < m; i++) {
    if (b[a[i]] == 0) {
      b[a[i]] = a[i + 1] - a[i];
      if (b[a[i]] <= 0) {
        b[a[i]] = n + b[a[i]];
      }
    } else {
      int z = b[a[i]];
      if ((a[i + 1] - a[i]) != z && (n - a[i + 1] + a[i]) != z) {
        cout << -1;
        return 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] != 0) {
      y = st.size();
      st.insert(b[i]);
      if (st.size() == y) {
        cout << -1;
        return 0;
      }
    }
  }
  for (int j = 1; j <= n; j++) {
    if (b[j] == 0) {
      for (int i = 1; i <= n; i++) {
        x = st.size();
        st.insert(i);
        if (x < st.size()) {
          cout << i << " ";
          break;
        }
      }
    } else
      cout << b[j] << " ";
  }
  return 0;
}
