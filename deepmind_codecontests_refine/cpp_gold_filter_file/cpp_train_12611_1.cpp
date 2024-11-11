#include <bits/stdc++.h>
using namespace std;
vector<long long> v[105];
long long ans[105], idx;
long long n, m;
long long door[105];
bool cmp(long long a, long long b) {
  if (a < idx) a += n;
  if (b < idx) b += n;
  if (a > b)
    return 1;
  else
    return 0;
}
void solve() {
  for (long long i = 1; i <= n; i++) {
    if (v[i].size() > 0) {
      long long siz = v[i].size();
      long long dist = (siz - 1) * n + v[i][siz - 1] - i;
      if (v[i][siz - 1] - i < 0) dist += n;
      door[i] = dist;
    }
  }
}
int main() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back(y);
  }
  for (idx = 1; idx <= n; idx++) {
    sort(v[idx].begin(), v[idx].end(), cmp);
  }
  solve();
  for (long long i = 1; i <= n; i++) {
    long long val = 0;
    for (long long j = 1; j <= n; j++) {
      if (v[j].size() == 0) continue;
      long long tmp = j - i;
      if (j - i < 0) tmp += n;
      val = max(val, door[j] + tmp);
    }
    ans[i] = val;
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
}
