#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string p, t;
  cin >> p >> t;
  vector<int> perm(p.size());
  for (auto &it : perm) cin >> it, it--;
  int n = perm.size(), l1 = p.size(), l2 = t.size();
  int lo = 0, hi = perm.size() - 1, ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    vector<int> count(n, 0);
    for (int e = 0; e <= mid; e++) count[perm[e]] = 1;
    int i = 0, j = 0;
    while (i < l1 && j < l2) {
      if (count[i])
        i++;
      else {
        if (p[i] == t[j])
          i++, j++;
        else
          i++;
      }
    }
    if (j == l2)
      ans = mid, lo = mid + 1;
    else
      hi = mid - 1;
  }
  cout << ans + 1 << endl;
  return 0;
}
