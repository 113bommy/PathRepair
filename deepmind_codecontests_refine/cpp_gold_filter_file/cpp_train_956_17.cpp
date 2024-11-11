#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> d;
  vector<int> ans(1e7);
  vector<int> a(m);
  vector<int> res;
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  bool ok = true;
  int pos = d;
  for (int i = 0; i < m; ++i) {
    for (int j = pos; j <= pos + (a[i] - 1); ++j) {
      ans[j] = i + 1;
    }
    pos += (a[i] - 1);
    for (int j = pos + 1; j < pos + d - 1; ++j) {
      ans[j] = 0;
    }
    pos += d;
  }
  if (pos <= n) {
    cout << "NO" << '\n';
    return 0;
  }
  --pos;
  int cnt = pos - n;
  for (int i = pos; i >= 1; --i) {
    if (ans[i] == 0) {
      if (cnt)
        --cnt;
      else
        res.push_back(0);
    } else {
      res.push_back(ans[i]);
    }
  }
  cout << "YES" << '\n';
  reverse(res.begin(), res.end());
  for (auto it : res) {
    cout << it << " ";
  }
  cout << '\n';
  return 0;
}
