#include <bits/stdc++.h>
using namespace std;
int n;
pair<long long, int> st[400001];
long long ans[200001];
long long prv[200001];
multiset<int> s;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long l, r;
    cin >> l >> r;
    st[2 * i - 1] = {l, -i};
    st[2 * i] = {r, i};
    ans[i] = 0;
  }
  sort(st + 1, st + 2 * n + 1);
  long long pf = 0;
  st[0].second = 1;
  for (int i = 1; i <= 2 * n; i++) {
    int ps = s.size();
    if (st[i].second < 0) {
      s.insert(-st[i].second);
    } else {
      s.erase(s.find(st[i].second));
    }
    if (s.size() == 1 && st[i].second > 0 && st[i + 1].second < 0 &&
        st[i + 1].first != st[i].first)
      ans[*(s.begin())]++;
    else if (s.size() == 1 && st[i].second < 0 && st[i + 1].second > 0)
      ans[*s.begin()]--;
    if (s.size() == 0) pf++;
  }
  long long mx = -1e9;
  for (int i = 1; i <= n; i++) mx = max(mx, ans[i]);
  cout << mx + pf << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
