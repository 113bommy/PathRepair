#include <bits/stdc++.h>
const int inf = 1e9;
const int mod = (int)1e9 + 7;
using namespace std;
template <class T>
void smin(T& a, T val) {
  if (a > val) a = val;
}
template <class T>
void smax(T& a, T val) {
  if (a < val) a = val;
}
const int N = (int)1e5 + 10;
int n, a[N];
void solve() {
  int q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> diff;
  for (int i = 0; i + 1 < n; ++i) {
    diff.push_back(abs(a[i] - a[i + 1]));
  };
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    vector<int> v;
    v.push_back(inf);
    for (int i = l; i + 1 <= r; ++i) {
      v.push_back(diff[i]);
    }
    stack<int> s;
    int ans = 0;
    s.push(0);
    ;
    for (int i = 1; i < (int)(v.size()); ++i) {
      while (!s.empty() and v[i] > v[s.top()]) {
        int x = s.top();
        s.pop();
        int righthalf = i - x;
        int leftHalf = 1;
        if (!s.empty()) leftHalf = x - s.top();
        ans += v[x] * 1LL * righthalf * 1LL * leftHalf;
      }
      s.push(i);
    }
    while (!s.empty()) {
      int x = s.top();
      s.pop();
      if (x == 0) break;
      int leftHalf = 1;
      if (!s.empty()) leftHalf = x - s.top();
      ans += leftHalf * 1LL * v[x] * 1LL * ((int)(v.size()) - x);
    }
    cout << ans << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
