#include <bits/stdc++.h>
using namespace std;
map<int, int> M;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int a = 0; a < n; a++) {
    int den;
    cin >> den;
    for (int b = 1; b <= k; b++) {
      if (M.find(b * den) == M.end()) M[b * den] = b;
      if (M.find(b * den) != M.end() && b < M[b * den]) M[b * den] = b;
    }
  }
  int q;
  cin >> q;
  for (int d = 0; d < q; d++) {
    int val;
    cin >> val;
    int lb = 21;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
      int loquefalta = val - it->first;
      if (loquefalta == 0) lb = it->second;
      map<int, int>::iterator itlow = M.lower_bound(loquefalta);
      if (itlow->first == loquefalta && it->second + itlow->second <= k) {
        lb = min(lb, it->second + itlow->second);
      }
    }
    if (lb < 21) {
      cout << lb << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
