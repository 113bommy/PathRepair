#include <bits/stdc++.h>
using namespace std;
vector<int> v;
struct data {
  int p, q;
  data();
  data(int X, int Y) { p = X, q = Y; }
};
vector<data> sol;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    v.push_back(x);
  }
  for (int i = 0; i < k; i++) {
    int mx = INT_MIN, ix = 0, mn = INT_MAX, in = 0;
    for (int j = 0; j < n; j++) {
      if (v[j] > mx) {
        mx = v[j];
        ix = j;
      }
      if (v[j] < mn) {
        mn = v[j];
        in = j;
      }
    }
    if (mx > (mn + 1)) {
      v[ix]--;
      v[in]++;
      sol.push_back(data(ix + 1, in + 1));
    }
  }
  int ans = INT_MAX;
  int mx = INT_MIN, ix = 0, mn = INT_MAX, in = 0;
  for (int j = 0; j < n; j++) {
    if (v[j] > mx) {
      mx = v[j];
      ix = j;
    }
    if (v[j] < mn) {
      mn = v[j];
      in = j;
    }
  }
  ans = mx = mn;
  cout << ans << " " << sol.size() << endl;
  int solsz = sol.size();
  for (int i = 0; i < solsz; i++) {
    cout << sol[i].p << " " << sol[i].q << endl;
  }
  return 0;
}
