#include <bits/stdc++.h>
using namespace std;
long long p = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, s;
  cin >> n >> s;
  vector<long long> a(n);
  vector<pair<long long, long long>> b;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  b.push_back(make_pair(a[0], 1));
  for (long long i = 1; i < n; i++) {
    if (a[i] == b[b.size() - 1].first) {
      b[b.size() - 1].second++;
    } else {
      b.push_back(make_pair(a[i], 1));
    }
  }
  long long m = b.size();
  long long pre[m], suf[m];
  pre[0] = b[0].second;
  suf[m - 1] = b[m - 1].second;
  for (long long i = 1; i < m; i++) {
    pre[i] = pre[i - 1] + b[i].second;
  }
  for (long long i = m - 2; i >= 0; i--) {
    suf[i] = suf[i + 1] + b[i].second;
  }
  long long ans;
  long long x = (n * ceil(log2(m)));
  if (x <= 8 * s) {
    ans = 0;
  } else {
    long long k = (long long)pow(2, (8 * s) / n);
    ans = min(suf[k], pre[m - k - 1]);
    for (long long i = 1; i <= m - k - 1; i++) {
      ans = min(ans, pre[i - 1] + suf[i + k]);
    }
  }
  cout << ans << endl;
}
