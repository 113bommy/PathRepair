#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, k, m, a[N];
deque<pair<long long, long long> > frst, last, v;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (m <= 2) {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (v.size() == 0 || a[j] != v[v.size() - 1].first)
          v.push_back({a[j], 1});
        else
          v[v.size() - 1].second++;
        if (v[v.size() - 1].second == k) v.pop_back();
      }
    long long ans = 0;
    for (int i = 0; i < v.size(); i++) ans += v[i].second;
    cout << ans;
    return 0;
  }
  for (int j = 0; j < n; j++) {
    if (v.size() == 0 || a[j] != v[v.size() - 1].first)
      v.push_back({a[j], 1});
    else
      v[v.size() - 1].second++;
    if (v[v.size() - 1].second == k) v.pop_back();
  }
  frst = v;
  last = v;
  for (int i = 0; i < v.size(); i++) assert(v[i].second != 0);
  while (v.size() > 0) {
    assert(v[0].second != 0);
    assert(v[v.size() - 1].second != 0);
    if (v[0].first != v[v.size() - 1].first) break;
    if (v.size() == 1) {
      long long cnt = (m - 2) * v[0].second;
      if (frst[frst.size() - 1].first == v[0].first) {
        cnt += frst[frst.size() - 1].second;
        frst.pop_back();
      }
      if (last[0].first == v[0].first) {
        cnt += last[0].second;
        last.pop_front();
      }
      cnt %= k;
      if (cnt == 0) {
        v = frst;
        for (int i = 0; i < last.size(); i++) {
          if (v.size() == 0 || last[i].first != v[v.size() - 1].first)
            v.push_back(last[i]);
          else
            v[v.size() - 1].second += last[i].second;
          while (v[v.size() - 1].second >= k) v[v.size() - 1].second -= k;
          if (v[v.size() - 1].second == 0) v.pop_back();
        }
        long long ans = 0;
        for (int i = 0; i < v.size(); i++) ans += v[i].second;
        cout << ans;
        return 0;
      }
      long long ans = cnt;
      for (int i = 0; i < frst.size(); i++) {
        assert(frst[i].second != 0);
        ans += frst[i].second;
      }
      for (int i = 0; i < last.size(); i++) {
        assert(last[i].second != 0);
        ans += last[i].second;
      }
      cout << ans;
      return 0;
    }
    if (v[0].second + v[v.size() - 1].second < k) break;
    long long dec_first = min(v[0].second, k);
    long long dec_last = k - dec_first;
    v[0].second -= dec_first;
    last[0].second -= dec_first;
    v[v.size() - 1].second -= dec_last;
    frst[frst.size() - 1].second -= dec_last;
    if (v[0].second == 0) {
      v.pop_front();
      last.pop_front();
    }
    if (v[v.size() - 1].second == 0) {
      v.pop_back();
      frst.pop_back();
    }
  }
  if (v.size() == 0) {
    v = frst;
    for (int i = 0; i < last.size(); i++) {
      if (v.size() > 0) assert(v[v.size() - 1].second != 0);
      assert(last[i].second != 0);
      if (v.size() == 0 || last[i].first != v[v.size() - 1].first)
        v.push_back(last[i]);
      else
        v[v.size() - 1].second += last[i].second;
      while (v[v.size() - 1].second >= k) v[v.size() - 1].second -= k;
      if (v[v.size() - 1].second == 0) v.pop_back();
    }
    long long ans = 0;
    for (int i = 0; i < v.size(); i++) {
      assert(v[i].second != 0);
      ans += v[i].second;
    }
    cout << ans;
    return 0;
  } else {
    long long ans = 0;
    long long ans2 = 0;
    for (int i = 0; i < v.size(); i++) {
      assert(v[i].second != 0);
      ans += v[i].second;
    }
    for (int i = 0; i < frst.size(); i++) {
      assert(frst[i].second != 0);
      ans2 += frst[i].second;
    }
    for (int i = 0; i < last.size(); i++) {
      assert(last[i].second != 0);
      ans2 += last[i].second;
    }
    cout << (m - 2) * ans + ans2;
    return 0;
  }
  return 0;
}
