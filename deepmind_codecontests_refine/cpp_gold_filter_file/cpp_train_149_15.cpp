#include <bits/stdc++.h>
using namespace std;
vector<int> ans, r;
int a[600], f[600], t[2000], q[10000], s = 0;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < m; i++) {
    if (f[t[i]] == 0) {
      ans.push_back(t[i]);
      f[t[i]] = 1;
    }
  }
  for (int i = 0; i < ans.size(); i++) q[i] = ans[i];
  for (int i = 0; i < m; i++) {
    int j = 0;
    while (q[j] != t[i]) {
      s += a[q[j] - 1];
      j++;
    }
    r.clear();
    for (int x = 0; x < n; x++)
      if (x != j) r.push_back(q[x]);
    q[0] = q[j];
    for (int i = 1; i <= r.size(); i++) q[i] = r[i - 1];
  }
  cout << s;
  return 0;
}
