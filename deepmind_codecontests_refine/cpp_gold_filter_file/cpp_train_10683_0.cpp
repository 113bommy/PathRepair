#include <bits/stdc++.h>
using namespace std;
const long long maxN = 2 * 1e5;
vector<long long> mem, f[maxN];
bool kt[maxN], ok;
long long n, m, s, t, a[maxN], b[maxN], num[3];
void dfs(long long u) {
  mem.push_back(u);
  kt[u] = 1;
  if (u == t) {
    ok = 1;
    return;
  }
  if (ok) return;
  for (int i = 0; i < f[u].size(); ++i)
    if (kt[f[u][i]] == 0) dfs(f[u][i]);
  return;
}
int main() {
  cin >> n >> m;
  s = m + 1;
  t = m + 2;
  cin >> num[0];
  for (long long i = (1); i <= (num[0]); ++i) cin >> a[i];
  for (long long i = (2); i <= (n); ++i) {
    cin >> num[1];
    for (long long j = (1); j <= (num[1]); ++j) cin >> b[j];
    int j = 0;
    while (j <= min(num[0], num[1]) && a[j] == b[j]) ++j;
    if (j > min(num[0], num[1])) {
      if (num[0] > num[1]) {
        cout << "No";
        return 0;
      }
      num[0] = num[1];
      for (long long t = (1); t <= (num[0]); ++t) a[t] = b[t];
      continue;
    }
    if (a[j] > b[j]) {
      f[s].push_back(a[j]);
      f[b[j]].push_back(t);
    } else {
      f[b[j]].push_back(a[j]);
    }
    num[0] = num[1];
    for (long long t = (1); t <= (num[0]); ++t) a[t] = b[t];
  }
  ok = 0;
  dfs(s);
  if (ok) {
    cout << "No";
    return 0;
  }
  cout << "Yes" << endl;
  cout << mem.size() - 1 << endl;
  for (long long i = (1); i <= (mem.size() - 1); ++i) cout << mem[i] << " ";
  return 0;
}
