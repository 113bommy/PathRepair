#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, t1, t2, k;
  cin >> n >> m >> t1 >> t2 >> k;
  vector<long long> v1(n);
  vector<long long> v2(m);
  vector<long long> ans;
  for (long long i = 0; i < n; i++) {
    cin >> v1[i];
    v1[i] += t1;
  }
  for (long long i = 0; i < m; i++) {
    cin >> v2[i];
  }
  if (k >= n || k >= m) {
    cout << -1 << endl;
    return 0;
  }
  for (long long i = 0; i < k; i++) {
    long long hold =
        (lower_bound(v2.begin(), v2.end(), v1[i + 1]) - v2.begin());
    long long bold = m - hold;
    if (bold <= (k - i - 1)) {
      cout << -1 << endl;
      return 0;
    } else {
      long long check = k - (i + 1);
      ans.push_back(v2[hold + check] + t2);
    }
  }
  long long t = v1[0];
  long long q = lower_bound(v2.begin(), v2.end(), v1[0]) - v2.begin();
  q = q + k;
  if (q >= m) {
    cout << -1 << endl;
    return 0;
  } else
    ans.push_back(v2[q] + t2);
  long long ans1 = *max_element(ans.begin(), ans.end());
  cout << ans1 << endl;
  return 0;
}
