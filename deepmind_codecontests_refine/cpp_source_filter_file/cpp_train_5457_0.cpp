#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5002;
int n, m, a[N][N], c[N][N];
string s[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0, ggdem = n; i < ggdem; i++) cin >> s[i];
  for (int i = 0, ggdem = n; i < ggdem; i++)
    for (int j = 0, ggdem = m; j < ggdem; j++) a[i][j] = s[i][j] - '0';
  for (int i = 0, ggdem = n; i < ggdem; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (a[i][j])
        c[i][j] = c[i][j + 1] + 1;
      else
        c[i][j] = 0;
    }
  }
  int res = 0;
  for (int j = 0, ggdem = m; j < ggdem; j++) {
    vector<int> cnt(5001);
    for (int i = 0, ggdem = n; i < ggdem; i++) cnt[a[i][j]]++;
    vector<int> v;
    for (int i = 0, ggdem = ((int)(cnt).size()); i < ggdem; i++)
      for (int j = 0, ggdem = cnt[i]; j < ggdem; j++) v.push_back(i);
    reverse(v.begin(), v.end());
    for (int i = 0, ggdem = ((int)(v).size()); i < ggdem; i++)
      res = max(res, (i + 1) * v[i]);
  }
  cout << res << endl;
}
