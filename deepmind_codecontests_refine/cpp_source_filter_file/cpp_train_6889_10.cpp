#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 100;
long long ans[nax], f[nax];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n, w;
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    vector<int> a(l + 1);
    deque<int> q;
    int len = w - l;
    a[0] = 0;
    q.push_back(0);
    for (int j = 1; j <= l; j++) {
      cin >> a[j];
      while (q.size() && a[j] > a[q.back()]) q.pop_back();
      q.push_back(j);
      while (q.size() && q.front() < j - len) q.pop_front();
      ans[j] += a[q.front()];
    }
    int at = w;
    int mx = 0;
    for (int j = l; j >= 1; j--) {
      if (at <= l) break;
      mx = max(mx, a[j]);
      ans[at] += mx;
      at--;
    }
    mx = 0;
    for (int j = l; j >= 1; j--) {
      mx = max(mx, a[j]);
    }
    if (l + 1 < w - len) {
      f[l + 1] += mx;
      f[w - l + 1] -= mx;
    }
  }
  long long cur = 0;
  for (int i = 1; i <= w; i++) {
    cur += f[i];
    ans[i] += cur;
  }
  for (int i = 1; i <= w; i++) cout << ans[i] << ' ';
  cout << endl;
}
