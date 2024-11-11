#include <bits/stdc++.h>
using namespace std;
const int maxn = 400100;
int n, a[maxn], cnt[maxn];
int s[maxn], pos[maxn], val[maxn];
int ans, T = 300;
vector<int> npos[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
    npos[a[i]].push_back(i);
  }
  int cntmode = 0;
  for (int i = 1; i <= n; ++i) cntmode = max(cntmode, cnt[i]);
  vector<int> modes;
  for (int i = 1; i <= n; ++i)
    if (cnt[i] == cntmode) modes.push_back(i);
  if (modes.size() >= 2) return cout << n, 0;
  int M = modes[0];
  for (int m = 1; m <= n; ++m)
    if (m != M && cnt[m] > T) {
      for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + (a[i] == M) - (a[i] == m);
      }
      for (int i = 0; i <= 2 * n + 1; ++i) pos[i] = n + 1;
      for (int i = 0; i <= n; ++i) pos[s[i] + n] = min(pos[s[i] + n], i);
      for (int i = 1; i <= n; ++i) ans = max(ans, i - pos[s[i] + n]);
    }
  npos[M].insert(npos[M].begin(), 0);
  npos[M].push_back(n + 1);
  for (int orc = 0; orc <= T + 1; ++orc) {
    for (int i = 0; i <= n; ++i) val[i] = n + 1;
    for (int i = 1; i <= n; ++i) {
      if (i == M) continue;
      for (int j = 0; j < (int)npos[i].size(); ++j) {
        if (j + orc - 1 < (int)npos[i].size()) {
          val[npos[i][j]] = npos[i][max(j + orc - 1, j)];
        }
      }
    }
    for (int i = 0; i <= n + 1; ++i) pos[i] = -1;
    for (int i = 1; i <= n; ++i) pos[val[i]] = max(pos[val[i]], i);
    for (int i = 1; i <= n; ++i) pos[i] = max(pos[i], pos[i - 1]);
    for (int i = 0; i < npos[M].size(); ++i) {
      if (i + orc + 1 >= npos[M].size()) break;
      int Rl = npos[M][i] + 1, Rr = npos[M][i + orc + 1] - 1;
      if (pos[Rr] >= Rl) ans = max(ans, Rr - Rl + 1);
    }
  }
  cout << ans;
  return 0;
}
