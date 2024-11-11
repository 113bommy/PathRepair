#include <bits/stdc++.h>
using namespace std;
int n, a[100001], ans_, now;
pair<int, int> p[100001], q[100001];
vector<pair<int, int> > ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    q[i] = p[i] = make_pair(a[i], i);
  }
  sort(p + 1, p + n + 1);
  bool zero = 1;
  for (int i = 1; i < n; ++i)
    if (a[i] > a[i + 1]) zero = 0;
  if (zero) {
    cout << 0 << endl;
    return 0;
  }
  now = -1;
  for (int i = 1; i <= n; ++i) {
    bool lucky = 1;
    for (int j = a[i]; j; j /= 10)
      if (j % 10 != 4 && j % 10 != 7) lucky = 0;
    if (lucky) {
      now = i;
      for (; q[now].second != p[now].second;) {
        ans.push_back(make_pair(now, p[now].second));
        int tmp = p[now].second;
        swap(q[now], q[p[now].second]);
        now = tmp;
      }
      break;
    }
  }
  if (now == -1) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    if (q[i].second != p[i].second) {
      int tmp = now;
      if (now != i) {
        ans.push_back(make_pair(now, i));
        swap(q[now], q[i]);
        now = i;
      }
      for (; q[now].second != p[now].second && p[now].second != i;) {
        ans.push_back(make_pair(now, p[now].second));
        int tmp = p[now].second;
        swap(q[now], q[p[now].second]);
        now = p[now].second;
      }
      ans.push_back(make_pair(now, tmp));
      swap(q[now], q[tmp]);
      now = tmp;
    }
  int ans_ = ans.size();
  cout << ans_ << endl;
  for (int i = 0; i < ans_; ++i)
    cout << ans[i].first << ' ' << ans[i].second << endl;
  return 0;
}
