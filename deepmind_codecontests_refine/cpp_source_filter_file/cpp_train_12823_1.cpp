#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[5][200], ans;
vector<pair<int, int> > v, vec;
int getidx(int i, int j) { return (i - 1) * m + j; }
int geti(int idx) { return (idx - 1) / m; }
int getj(int idx) { return (((idx - 1) % m) + 1); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    v.clear();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        v.push_back({a[i][j], getidx(i, j)});
      }
    }
    ans = 0;
    sort(v.rbegin(), v.rend());
    if (n < 4 || m == 1) {
      for (int i = 0; i < n; i++) {
        ans += v[i].first;
      }
    } else {
      int ar[] = {0, 0, 0, 0, 1, 1, 1, 1};
      do {
        int tmp = 0;
        vec.clear();
        for (int i = 0; i < 8; i++) {
          if (ar[i] == 1) {
            int ii = geti(v[i].second);
            int jj = getj(v[i].second);
            vec.push_back({jj, ii});
            tmp += v[i].first;
          }
        }
        sort(vec.begin(), vec.end());
        int ct = 1;
        for (int i = 1; i < 4; i++)
          if (vec[i].first != vec[i - 1].first) ct++;
        if (ct != 2 || vec[1].first == vec[2].first ||
            ((vec[1].second - vec[0].second + 4) % 4 ==
             (vec[3].second - vec[2].second + 4) % 4)) {
          ans = max(ans, tmp);
        }
      } while (next_permutation(ar, ar + 8));
    }
    cout << ans << "\n";
  }
}
