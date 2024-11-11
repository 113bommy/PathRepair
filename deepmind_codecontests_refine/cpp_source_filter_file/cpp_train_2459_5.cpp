#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
long long f[N], pre[N], W, sum;
int q[N], n, T;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (cin >> T; T--;) {
    cin >> n >> W;
    int t = 0, w = 0;
    q[0] = f[0] = pre[0] = sum = 0;
    for (int i = 1, j = 0; i <= n; ++i) {
      int x;
      cin >> x;
      sum += x;
      for (; t <= w && sum - pre[q[t]] > W; ++t)
        ;
      for (; j < i && sum - pre[j] > W; ++j)
        ;
      if (t <= w)
        f[i] = f[q[t]] + sum - pre[q[t]];
      else
        f[i] = 0;
      if (j) f[i] = max(f[i], f[j - 1] + W);
      if (i != n) {
        cin >> x;
        sum += x;
        pre[i] = sum;
        for (; t <= w && f[q[w]] - pre[q[w]] <= f[i] - pre[i]; --w)
          ;
        q[++w] = i;
      }
    }
    cout << f[n] << '\n';
  }
  return 0;
}
