#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> odp;
  for (int i = 0; i < k; ++i) odp.push_back(1);
  odp.push_back(n);
  int r;
  if (m == n) {
    odp.push_back(n + 2);
    r = (n == 2) ? max(1, k - 1) : k - 1;
  }
  if (m == n - 1) {
    odp.push_back(n + 1);
    r = max(0, k - 2);
  }
  if (m <= n - 2) r = k - 1;
  for (int i = 0; i < r; ++i) odp.push_back(n + 1);
  cout << odp.size() << endl;
  for (int i = 0; i < odp.size(); ++i) cout << odp[i] << " ";
  return 0;
}
