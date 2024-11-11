#include <bits/stdc++.h>
using namespace std;
bool check(string& s, int d) {
  int cur = 0, ind = -1;
  while (true) {
    int ni = ind + d;
    if (cur + d >= s.size() + 1) return true;
    bool suc = false;
    for (int i = ind + 1; i <= ni; i++) {
      if (s[i] == 'R') {
        suc = true;
        ind = i;
        cur = ind + 1;
      }
    }
    if (!suc) break;
  }
  return false;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<long long>> a(n, vector<long long>(2));
  vector<long long> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i][1];
    k.push_back(a[i][1] - a[i][0]);
  }
  sort(k.begin(), k.end());
  long long ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    long long st = 0, end = n - 1, ind = -1, val = a[i][0] - a[i][1];
    while (st <= end) {
      int mid = (st + end) / 2;
      if (k[mid] < val) {
        ind = mid;
        st = mid + 1;
      } else
        end = mid - 1;
    }
    ans += ind + 1;
    if (a[i][0] > a[i][1]) cnt++;
  }
  ans -= cnt;
  cout << ans / 2;
}
