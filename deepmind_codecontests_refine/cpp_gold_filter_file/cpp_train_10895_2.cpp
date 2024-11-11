#include <bits/stdc++.h>
using namespace std;
set<long long int> s;
long long int a[100005];
long long int v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, q;
  cin >> n >> q;
  v = 1;
  s.insert(0);
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pair<long long int, long long int> p[q + 1];
  long long int ans[q + 1];
  p[q].first = -1;
  for (long long int i = 0; i < q; i++) {
    cin >> p[i].first >> ans[i];
    p[i].second = i;
  }
  sort(p, p + q);
  s.clear();
  s.insert(0);
  long long int y = 0;
  for (long long int i = 1; i <= n; i++) {
    auto x = s.find(a[i]);
    if (x == s.end()) {
      for (auto j : s) {
        s.insert((a[i] ^ j));
      }
    } else {
      v *= 2;
      v %= 1000000007;
    }
    while (p[y].first == i) {
      x = s.find(ans[p[y].second]);
      if (x != s.end())
        ans[p[y].second] = v;
      else
        ans[p[y].second] = 0;
      y++;
    }
  }
  for (long long int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}
