#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int N = *max_element(a.begin(), a.end()) + 1;
  vector<int> cnt(N);
  int ret = 0;
  for (int rot = 0; rot < 2; rot++) {
    for (int i = 1; i <= n; i++) {
      cnt[a[i - 1]]++;
      int mx = *max_element(cnt.begin(), cnt.end());
      int c = count(cnt.begin(), cnt.end(), mx);
      if (c >= 2) ret = max(ret, i);
    }
    reverse(a.begin(), a.end());
    fill(cnt.begin(), cnt.end(), 0);
  }
  auto check = [&](vector<int> p, vector<int> q) {
    for (int i = 0; i < (int)p.size(); i++) {
      if (q[i] >= p[i]) return true;
    }
    return false;
  };
  vector<vector<vector<int>>> dif(N);
  vector<vector<int>> pos(N);
  for (int b = 1; b < n; b++) {
    {
      cnt[a[b - 1]]++;
      int mx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
      if (count(cnt.begin(), cnt.end(), cnt[mx]) == 1 && a[b] == mx &&
          dif[mx].size()) {
        int id = mx;
        vector<int> now;
        for (int i = 0; i < N; i++) {
          if (i == id) continue;
          now.push_back(cnt[id] - cnt[i]);
        }
        int lo = -1, hi = dif[mx].size();
        while (hi - lo > 1) {
          int mid = (hi + lo) >> 1;
          if (check(now, dif[id][mid]))
            hi = mid;
          else
            lo = mid;
        }
        if (hi < (int)dif[mx].size()) {
          ret = max(ret, b - pos[id][hi]);
        }
      }
    }
    int id = a[b - 1];
    vector<int> now;
    for (int i = 0; i < N; i++) {
      if (i == id) continue;
      now.push_back(cnt[id] - cnt[i]);
    }
    if (dif[id].size()) {
      for (int i = 0; i < N - 1; i++) {
        now[i] = max(now[i], dif[id].back()[i]);
      }
    }
    dif[id].push_back(now);
    pos[id].push_back(b);
  }
  cout << ret;
  return 0;
}
