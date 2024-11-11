#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
void desperate_optimization(bool submitting = true, int precision = 10) {
  if (!submitting) return;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(precision);
}
int main() {
  desperate_optimization(false);
  int n, u, v, x, y, i, j, count = 0, temp, flag1 = 0, flag2 = 0;
  vector<int> tree[1005];
  cin >> n;
  for (i = 2; i <= n; i++) {
    cin >> x;
    tree[x].push_back(i);
  }
  for (i = 1; i <= n; i++) {
    x = tree[i].size();
    if (x) {
      count = 0;
      for (j = 0; j < tree[i].size(); j++) {
        if (tree[tree[i][j]].size() == 0) count++;
      }
      if (count != 3) return cout << "NO", 0;
    }
  }
  return cout << "YES", 0;
  int do_not_hack;
  return 0;
}
