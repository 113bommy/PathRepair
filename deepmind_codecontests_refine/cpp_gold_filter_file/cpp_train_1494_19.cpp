#include <bits/stdc++.h>
using namespace std;
const int LOGN = 20;
const int INF = int(1e9);
struct ds {
  int l;
  int ans;
  int val;
};
vector<ds> a[200005];
vector<int> w;
int c[200005];
int main() {
  int n, m, k, mx;
  cin >> n >> m >> k;
  mx = 0;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    cin >> c[i];
    mx = max(mx, c[i]);
  }
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    ds* ds1 = new ds;
    ds1->val = i + 1;
    a[c[i]].push_back(*ds1);
  }
  int sol = 0;
  for (__typeof(mx + 1) i = (0) - ((0) > (mx + 1));
       i != (mx + 1) - ((0) > (mx + 1)); i += 1 - 2 * ((0) > (mx + 1))) {
    if (a[i].size() > 0) {
      int p1 = 0, p2 = 0, u = 0, sum = 1;
      while (p2 < a[i].size()) {
        if (u <= k) {
          sol = max(sol, sum);
          u += a[i][p2 + 1].val - a[i][p2].val - 1;
          p2++;
          sum++;
        } else {
          u -= a[i][p1 + 1].val - a[i][p1].val - 1;
          sum--;
          p1++;
        }
      }
    }
  }
  cout << sol << endl;
  return 0;
}
