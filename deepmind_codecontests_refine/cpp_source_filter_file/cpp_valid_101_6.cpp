#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> lx(n), ly(m);
    vector<int> x(k), y(k);
    for (int& i : lx) cin >> i;
    for (int& i : ly) cin >> i;
    for (int i = 0; i < k; i++) {
      cin >> x[i] >> y[i];
    }
    sort(lx.begin(), lx.end()), sort(ly.begin(), ly.end());
    vector<int> ind(k);
    iota(ind.begin(), ind.end(), 0);
    auto solve = [&](vector<int>& lx, vector<int>& ly, vector<int>& x) {
      long long ans = 0;
      for (int i = 0, j = 0; i + 1 < lx.size(); i++) {
        int c = 0;
        map<int, int> com;
        int l = lx[i], r = lx[i + 1];
        while (j < k && x[ind[j]] <= l) j++;
        while (j < k && x[ind[j]] < r) {
          ans += c++;
          ans -= com[y[ind[j]]]++;
          j++;
        }
      }
      return ans;
    };
    sort(ind.begin(), ind.end(), [&](int i, int j) { return x[i] < x[j]; });
    long long ans = solve(lx, ly, x);
    sort(ind.begin(), ind.end(), [&](int i, int j) { return y[i] < y[j]; });
    ans += solve(ly, lx, y);
    cout << ans << "\n";
  }
}
