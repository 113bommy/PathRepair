#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2000000000;
const long long BIG = 1446803456761533460LL;
const int maxn = 100010;
const int maxm = 20;
const int maxm2 = 1 << maxm;
int n, m, d, A[maxn], cnt[maxm], brk[maxm2];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> d;
  for (int i = 0; i < m; ++i) {
    int s;
    cin >> s;
    for (int j = 0; j < s; ++j) {
      int p;
      cin >> p;
      --p;
      A[p] = i;
    }
  }
  int mask = (1 << m) - 1;
  for (int i = 0; i < d - 1; ++i) {
    if (cnt[A[i]]++ == 0) mask ^= 1 << A[i];
  }
  for (int i = 0; i < n - d + 1; ++i) {
    if (cnt[A[i + d - 1]]++ == 0) mask ^= 1 << A[i + d - 1];
    brk[mask] = 1;
    if (--cnt[A[i]] == 0) mask ^= 1 << A[i];
  }
  int ans = m;
  for (int b = (1 << m) - 1; b >= 0; --b) {
    if (!brk[b]) {
      ans = min(ans, (__builtin_popcount(b)));
    } else {
      int bb = b;
      while (bb) {
        int lb = bb & -bb;
        bb ^= lb;
        brk[b ^ lb] = 1;
      }
    }
  }
  cout << ans << '\n';
}
