#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
int main() {
  int n, q;
  cin >> n >> q;
  vi arr(n);
  for (ll i = (0); i < (n); ++i) {
    cin >> arr[i];
  }
  int mx = *max_element((arr).begin(), (arr).end());
  deque<int> dq((arr).begin(), (arr).end());
  vector<pii> ans;
  for (ll i = (0); i < (n - 1); ++i) {
    int a = dq[0], b = dq[1];
    ans.push_back(make_pair(a, b));
    dq.pop_front();
    dq.pop_front();
    if (a > b) {
      swap(a, b);
    }
    dq.push_front(b);
    dq.push_back(a);
  }
  for (ll i = (0); i < (q); ++i) {
    ll m;
    cin >> m;
    if (m < n) {
      cout << ans[m - 1].first << " " << ans[m - 1].second << "\n";
    } else {
      m -= n;
      m %= n - 1;
      cout << dq.front() << " " << dq[m + 1] << "\n";
    }
  }
  return 0;
}
