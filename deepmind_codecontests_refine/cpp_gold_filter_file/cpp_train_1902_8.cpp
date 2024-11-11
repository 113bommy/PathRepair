#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int tt, n, a[100005], l, r, mid, cnt[100005];
vector<int> x;
set<pair<int, int> > s;
bool ans(int k) {
  for (int i = 1; i <= n; i++) cnt[i] = 0;
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  s.clear();
  x.clear();
  for (int i = 1; i <= n; i++)
    if (cnt[i]) s.insert({cnt[i], i});
  for (int i = 0; i < n; i++) {
    if (i - k >= 0 and cnt[x[i - k]]) s.insert({cnt[x[i - k]], x[i - k]});
    if (s.size() == 0) return 0;
    auto it = s.end();
    --it;
    x.push_back((*it).second);
    s.erase(it);
    cnt[x[x.size() - 1]]--;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    l = 1, r = n;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (ans(mid))
        l = mid + 1;
      else
        r = mid - 1;
    }
    cout << r - 1 << '\n';
  }
  return 0;
}
