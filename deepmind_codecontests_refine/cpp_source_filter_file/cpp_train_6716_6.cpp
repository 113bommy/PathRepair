#include <bits/stdc++.h>
using namespace std;
int n, m, k, s, d1, d2;
int a[200020], b[200020];
vector<pair<int, int>> ty1, ty2;
bool bs(int index, bool flag = false) {
  long long int sum = 0;
  vector<pair<long long int, pair<int, int>>> temp;
  for (auto x : ty1) temp.push_back({1ll * a[index] * x.first, {x.second, 1}});
  for (auto x : ty2) temp.push_back({1ll * b[index] * x.first, {x.second, 2}});
  sort(temp.begin(), temp.end());
  for (int i = 0; i < k; i++) sum += temp[i].first;
  if (flag) {
    assert(sum <= s);
    for (int i = 0; i < k; i++) {
      if (temp[i].second.second == 1) {
        cout << temp[i].second.first << " " << d1 << "\n";
      } else
        cout << temp[i].second.first << " " << d2 << "\n";
    }
  }
  return sum <= s;
}
int main() {
  cin >> n >> m >> k >> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i == 0)
      a[i] = x;
    else
      a[i] = min(a[i - 1], x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i == 0)
      b[i] = x;
    else
      b[i] = min(b[i - 1], x);
  }
  for (int i = 0; i < m; i++) {
    int t, c;
    cin >> t >> c;
    if (t == 1)
      ty1.push_back({c, i + 1});
    else
      ty2.push_back({c, i + 1});
  }
  int lh = 0, rh = n - 1, ans = -2;
  while (lh <= rh) {
    int mid = (lh + rh) >> 1;
    if (bs(mid)) {
      ans = mid;
      rh = mid - 1;
    } else
      lh = mid + 1;
  }
  cout << ans + 1 << "\n";
  if (ans == -2) return 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[ans]) {
      d1 = i + 1;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == b[ans]) {
      d2 = i + 1;
      break;
    }
  }
  bs(ans + 1, true);
  return 0;
}
