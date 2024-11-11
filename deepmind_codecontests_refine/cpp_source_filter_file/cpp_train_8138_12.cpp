#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long bit1[200010], x[200010], sum, n, m;
vector<long long> v[200010];
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> x[i];
    v[x[i]].push_back(i);
  }
  for (long long i = 1; i < m; i++) {
    if (x[i] > x[i + 1] + 1) {
      bit1[x[i + 1] + 1]++;
      bit1[x[i]]--;
    }
    if (x[i + 1] > x[i] + 1) {
      bit1[x[i] + 1]++;
      bit1[x[i + 1]]--;
    }
  }
  for (long long i = 1; i <= n; i++) bit1[i] += bit1[i - 1];
  for (long long i = 1; i < m; i++) sum += abs(x[i + 1] - x[i]);
  for (long long i = 1; i <= n; i++) {
    long long res = sum;
    for (long long j = 0; j < v[i].size(); j++) {
      long long pre = v[i][j] - 1, nxt = v[i][j] + 1;
      if (pre >= 1 && x[pre] != i) {
        long long val = x[pre];
        if (x[pre] < i) val = x[pre] + 1;
        res = res - abs(x[pre] - i) + abs(val - 1);
      }
      if (nxt <= n && x[nxt] != i) {
        long long val = x[nxt];
        if (x[nxt] < i) val = x[nxt] + 1;
        res = res - abs(x[nxt] - i) + abs(val - 1);
      }
    }
    res -= bit1[i];
    cout << res << " ";
  }
  cout << endl;
  return 0;
}
