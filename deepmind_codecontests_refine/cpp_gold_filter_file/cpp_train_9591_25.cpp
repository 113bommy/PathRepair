#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j, k, n;
  cin >> n >> k;
  long long mx = 0, cnt1 = 0, cnt2 = 0, ans, a;
  vector<long long int> v;
  map<long long, long long> m;
  for (long long int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
    if (a == 1) {
      cnt1++;
      m[i % k]++;
    } else {
      m[i % k]--;
      cnt2++;
    }
  }
  for (long long int i = 0; i < k; i++) {
    ans = cnt1 - cnt2 - m[i];
    if (ans < 0) ans = -1 * ans;
    mx = max(ans, mx);
  }
  cout << mx;
}
