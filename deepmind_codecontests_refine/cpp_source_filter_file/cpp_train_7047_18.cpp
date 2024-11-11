#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a;
  a.push_back(-1);
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    a.push_back(u);
  }
  vector<long long> pre(n + 2);
  vector<long long> nxt(n + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  pre[n + 1] = pre[n];
  nxt[n] = n + 1;
  for (int i = n - 1; i > 0; i--) {
    if (a[i + 1] != 1) {
      nxt[i] = i + 1;
    } else {
      nxt[i] = nxt[i + 1];
    }
  }
  long long ans = 0;
  long long inf = 2e18;
  for (int l = 1; l <= n; l++) {
    int r = l;
    long long prod = 1;
    while (r <= n && inf / a[r] > prod) {
      prod *= a[r];
      long long su = pre[r] - pre[l - 1];
      r = nxt[r];
      if (prod % k == 0) {
        long long need = prod / k;
        long long maxSum = pre[r] - pre[l - 1];
        if (su <= need && maxSum >= need) {
          ans++;
        }
      }
    }
  }
  cout << ans << '\n';
}
