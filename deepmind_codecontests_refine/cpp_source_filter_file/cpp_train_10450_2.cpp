#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int main() {
  int n, q;
  long long t;
  cin >> n >> q >> t;
  vector<int> b(q + 1), c(q + 1);
  long long a[301], newa[301];
  long long x[100001];
  int G[301][301];
  int V[301];
  memset(x, 0, sizeof(x));
  memset(G, 0, sizeof(G));
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= q; ++i) {
    cin >> b[i] >> c[i];
    G[b[i]][c[i]] = 1;
  }
  memcpy(newa, a, sizeof(a));
  for (int i = 1; i <= n; ++i) {
    memset(V, 0, sizeof(V));
    stack<int> st;
    st.push(i);
    while (!st.empty()) {
      int p = st.top();
      st.pop();
      if (V[p]) {
        if (p == i) {
          cout << 0 << endl;
          return 0;
        }
        continue;
      }
      V[p] = 1;
      if (p != i) newa[p] = (newa[p] + a[i]) % mod;
      for (int j = 1; j <= n; ++j) {
        if (G[p][j]) {
          st.push(j);
        }
      }
    }
  }
  memcpy(a, newa, sizeof(a));
  for (int i = 1; i <= n; ++i) {
    bool isbottom = true;
    for (int j = 1; j <= n; ++j) {
      if (G[i][j]) {
        isbottom = false;
        break;
      }
    }
    if (!isbottom) {
      t -= a[i];
    }
  }
  if (t <= 0) {
    cout << 0 << endl;
    return 0;
  }
  x[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = a[i]; j <= t; ++j) {
      x[j] = (x[j] + x[j - a[i]]) % mod;
    }
  }
  cout << x[t] << endl;
  return 0;
}
