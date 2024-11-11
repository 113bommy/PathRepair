#include <bits/stdc++.h>
using namespace std;
struct w {
  long long sum, an;
  w() : sum(0), an(0){};
  w(long long _s, long long _a) : sum(_s), an(_a){};
};
int n;
vector<long long> a, b;
vector<w> dp[2];
w max(w q, w q2) {
  if (q.an < q2.an || q.an == q2.an && q.sum < q2.sum) return q2;
  return q;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  a.resize(n);
  b.resize(n);
  dp[0].resize(n);
  dp[1].resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  w zm0 = w(a[n - 1] + b[n - 1], b[n - 1]),
    zm1 = w(a[n - 1] + b[n - 1], a[n - 1]);
  dp[0][n - 1] = zm0;
  dp[1][n - 1] = zm1;
  for (int i = n - 2; i >= 0; i--) {
    zm0 = w(zm0.sum + a[i] + b[i],
            zm0.sum + zm0.an + b[i] * ((n - i - 1) * 2 + 1));
    dp[0][i] = max(zm0, w(dp[1][i + 1].sum + a[i] + b[i],
                          dp[1][i + 1].an + b[i] + 2 * dp[1][i + 1].sum));
    zm1 = w(zm1.sum + a[i] + b[i],
            zm1.sum + zm1.an + a[i] * ((n - i - 1) * 2 + 1));
    dp[1][i] = max(zm1, w(dp[0][i + 1].sum + a[i] + b[i],
                          dp[0][i + 1].an + a[i] + 2 * dp[0][i + 1].sum));
  }
  cout << dp[0][0].an;
  return 0;
}
