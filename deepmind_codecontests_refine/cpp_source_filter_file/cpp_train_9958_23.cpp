#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, m, a[MAXN], b[MAXN], si, sj, ans;
set<int> A;
int main() {
  cin >> n >> m;
  for (int ip = 0; ip < n; ip++) cin >> a[ip];
  for (int ip = 0; ip < m; ip++) cin >> b[ip];
  for (int i = 0; i < n; i++) si += a[i], A.insert(si);
  for (int i = 0; i < m; i++) {
    sj += a[i];
    if (A.find(sj) != A.end()) ans++;
  }
  cout << ans;
}
