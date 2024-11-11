#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3 * 1e5 + 5;
int A[MAXN];
map<int, int> nxtSet[MAXN];
int nxt[MAXN], dp[MAXN];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1, iend = n; i <= iend; ++i) scanf("%d", &A[i]);
  for (int i = 1, iend = n + 1; i <= iend; ++i) {
    nxt[i] = -1;
    nxtSet[i].clear();
    dp[i] = 0;
  }
  for (int i = n, iend = 1; i >= iend; --i) {
    if (nxtSet[i + 1].count(A[i])) {
      int p = nxtSet[i + 1][A[i]];
      nxt[i] = p;
      swap(nxtSet[i], nxtSet[p + 1]);
    }
    nxtSet[i][A[i]] = i;
  }
  long long res = 0;
  for (int i = n, iend = 1; i >= iend; --i) {
    if (nxt[i] != -1) dp[i] = dp[nxt[i] + 1] + 1;
    res += dp[i];
  }
  cout << res << endl;
}
int main() {
  int q;
  cin >> q;
  while (q--) solve();
  return 0;
}
