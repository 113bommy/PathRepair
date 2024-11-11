#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int a[n], b[m], c[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  set<int> s;
  for (int i = n - 1; i >= 0; i--) {
    s.insert(a[i]);
    c[i] = s.size();
  }
  for (int i = 0; i < m; i++) {
    cout << c[b[i] - 1] << endl;
  }
  return 0;
}
