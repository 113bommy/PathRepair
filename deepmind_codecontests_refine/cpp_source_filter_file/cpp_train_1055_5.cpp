#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  vector<pair<long long int, long long int>> v(n), vv(n);
  for (long long int i = 0; i < n; i++) {
    long long int a, b;
    cin >> a >> b;
    v[i] = {a, b};
    vv[i] = {b, a};
  }
  sort(vv.begin(), vv.end());
  reverse(vv.begin(), vv.end());
  long long int ans = 0, sum = 0;
  set<long long int> tmp;
  for (long long int i = 0; i < n; i++) {
    long long int val = vv[i].second, val2 = vv[i].first;
    while (i < n && vv[i].first == val2) {
      val = vv[i].second;
      if (tmp.size() == k && *(tmp.begin()) < val) {
        sum -= *(tmp.begin());
        tmp.erase(tmp.begin());
        tmp.insert(val);
        sum += val;
      } else if (tmp.size() < k) {
        tmp.insert(val);
        sum += val;
      }
      i++;
    }
    i--;
    ans = max(ans, sum * val2);
  }
  for (long long int i = 0; i < n; i++)
    ans = max(ans, v[i].first * v[i].second);
  cout << ans << "\n";
  return 0;
}
