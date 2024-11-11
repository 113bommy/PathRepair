#include <bits/stdc++.h>
using namespace std;
int ans, t, p, q, i, j, n, m, k, l, r, br1, br0;
bool b[36][36];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    ans = 0;
    vector<pair<int, int> > v;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        cin >> b[i][j];
      }
    }
    for (i = 1; i <= m; i++) {
      p = 1;
      q = i;
      br1 = br0 = 0;
      while (p <= n && q > 0) {
        if (b[p][q] == 1)
          br1++;
        else
          br0++;
        p++;
        q--;
      }
      v.push_back({br0, br1});
    }
    for (i = 2; i <= n; i++) {
      p = i;
      q = m;
      br1 = br0 = 0;
      while (p <= n && q > 0) {
        if (b[p][q] == 1)
          br1++;
        else
          br0++;
        p++;
        q--;
      }
      v.push_back({br0, br1});
    }
    for (i = 0; i < v.size() / 2; i++) {
      pair<int, int> pr = v[i];
      pair<int, int> pr1 = v[v.size() - i - 1];
      ans += min(pr.first + pr1.first, pr.second + pr1.second);
    }
    cout << ans << '\n';
  }
  return 0;
}
