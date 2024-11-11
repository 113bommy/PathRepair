#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)5e5;
int v[MAXN + 1];
int aib[MAXN + 1];
bool dp[MAXN + 1];
inline void update(int pos, int n, int val) {
  for (int i = pos; i <= n; i += (i & (-i))) {
    aib[i] += val;
  }
}
inline int query(int pos) {
  int ans = 0;
  for (int i = pos; i > 0; i -= (i & (-i))) {
    ans += aib[i];
  }
  return ans;
}
int main() {
  int i, n, k, d;
  ios::sync_with_stdio(false);
  cin >> n >> k >> d;
  for (i = 1; i <= n; i++) {
    cin >> v[i];
  }
  sort(v + 1, v + n + 1);
  int pos = 1;
  for (i = 1; i <= n; i++) {
    while (pos <= n && v[i] - v[pos] > d) {
      pos++;
    }
    if (pos == 1) {
      dp[i] = (i >= k);
    } else {
      dp[i] = ((query(i - k) - query(pos - 2)) > 0);
    }
    update(i, n, dp[i]);
  }
  if (dp[n] == 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
