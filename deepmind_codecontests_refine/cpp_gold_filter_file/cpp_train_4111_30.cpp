#include <bits/stdc++.h>
using namespace std;
const int maxN = 300 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 9;
long long ans;
pair<int, int> a[maxN];
int cnt[2 * maxN];
vector<pair<int, int> > que[maxN];
int mi[maxN], mx[maxN];
void solve(int s, int e) {
  if (e - s == 1) {
    ans++;
    return;
  }
  int mii = (s + e) >> 1;
  solve(s, mii);
  solve(mii, e);
  int mini = mod, maxi = 0;
  vector<pair<pair<int, int>, int> > q1, q2;
  for (int i = mii; i < e; i++) {
    int ps = a[i].second;
    mi[i] = mini = min(mini, ps);
    mx[i] = maxi = max(maxi, ps);
    q1.push_back({{mini, maxi}, i - mii + 1});
  }
  mini = mod;
  maxi = 0;
  for (int i = mii - 1; i >= s; i--) {
    int ps = a[i].second;
    mi[i] = mini = min(mini, ps);
    mx[i] = maxi = max(maxi, ps);
    q2.push_back({{mini, maxi}, mii - i});
  }
  for (int i = 0; i < q1.size(); i++) {
    int l = q1[i].first.first, r = q1[i].first.second, val = q1[i].second;
    int len = r - l + 1 - val;
    if (len) {
      len--;
      if (len < q2.size()) {
        int lx = q2[len].first.first, rx = q2[len].first.second,
            valx = q2[len].second;
        if (l < lx && rx < r) ans++;
      }
    }
  }
  for (int i = 0; i < q2.size(); i++) {
    int l = q2[i].first.first, r = q2[i].first.second, val = q2[i].second;
    int len = r - l + 1 - val;
    if (len) {
      len--;
      if (len < q1.size()) {
        int lx = q1[len].first.first, rx = q1[len].first.second,
            valx = q1[len].second;
        if (l < lx && rx < r) ans++;
      }
    }
  }
  for (int i = 0; i < q1.size(); i++) {
    int l = q1[i].first.first, r = q1[i].first.second, val = q1[i].second;
    int lo1 = s - 1, hi1 = mii;
    while (hi1 - lo1 > 1) {
      int mid = (hi1 + lo1) >> 1;
      if (mx[mid] < r)
        hi1 = mid;
      else
        lo1 = mid;
    }
    if (hi1 == s - 1) hi1 = s;
    int lo2 = s - 1, hi2 = mii;
    while (hi2 - lo2 > 1) {
      int mid = (hi2 + lo2) >> 1;
      if (mi[mid] > l)
        hi2 = mid;
      else
        lo2 = mid;
    }
    if (lo2 < hi1 || mi[s] > l || mx[mii - 1] > r) continue;
    int tmp = r + 1 - val;
    que[lo2].push_back({tmp, 1});
    que[hi1].push_back({tmp, -1});
  }
  for (int i = 0; i < q2.size(); i++) {
    int l = q2[i].first.first, r = q2[i].first.second, val = q2[i].second;
    int lo1 = mii - 1, hi1 = e;
    while (hi1 - lo1 > 1) {
      int mid = (hi1 + lo1) >> 1;
      if (mx[mid] < r)
        lo1 = mid;
      else
        hi1 = mid;
    }
    int lo2 = mii - 1, hi2 = e;
    while (hi2 - lo2 > 1) {
      int mid = (hi2 + lo2) >> 1;
      if (mi[mid] > l)
        lo2 = mid;
      else
        hi2 = mid;
    }
    if (hi2 > lo1 || mi[e - 1] > l || mx[mii] > r) continue;
    int tmp = r + 1 - val;
    que[hi2].push_back({tmp, 1});
    que[lo1].push_back({tmp, -1});
  }
  for (int i = mii; i < e; i++) {
    for (int j = 0; j < que[i].size(); j++)
      if (que[i][j].second == 1) cnt[que[i][j].first]++;
    int tmp = -q1[i - mii].second - q1[i - mii].first.first;
    ans += cnt[-tmp];
    for (int j = 0; j < que[i].size(); j++)
      if (que[i][j].second == -1) cnt[que[i][j].first]--;
  }
  for (int i = mii - 1; i >= s; i--) {
    for (int j = 0; j < que[i].size(); j++)
      if (que[i][j].second == 1) cnt[que[i][j].first]++;
    int tmp = -q2[mii - 1 - i].second - q2[mii - 1 - i].first.first;
    ans += cnt[-tmp];
    for (int j = 0; j < que[i].size(); j++)
      if (que[i][j].second == -1) cnt[que[i][j].first]--;
  }
  for (int i = s; i < e; i++) que[i].clear();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(a, a + n);
  solve(0, n);
  cout << ans << endl;
  return 0;
}
