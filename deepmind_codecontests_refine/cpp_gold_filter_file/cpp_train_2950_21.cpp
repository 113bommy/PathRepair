#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int n, k, h;
pair<pair<int, int>, int> a[maxN];
bool cmp(pair<pair<int, int>, int> A, pair<pair<int, int>, int> B) {
  if (A.first.first == B.first.first) return A.first.second < B.first.second;
  return A.first.first < B.first.first;
}
vector<int> res;
bool check(long double t) {
  int z = 1, cnt = 0;
  vector<int> tmp;
  for (int i = 0; i < n; i++) {
    if (t * a[i].first.second >= z * h) {
      z++;
      cnt++;
      tmp.push_back(a[i].second);
      if (cnt >= k) break;
    }
  }
  if (cnt >= k) {
    res.clear();
    for (int i = 0; i < k; i++) res.push_back(tmp[i]);
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> h;
  for (int i = 0; i < n; i++) cin >> a[i].first.first, a[i].second = i + 1;
  for (int i = 0; i < n; i++) cin >> a[i].first.second;
  sort(a, a + n, cmp);
  long double l = 0, r = 1e13;
  for (int i = 0; i < 200; i++) {
    long double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  cout << '\n';
  return 0;
}
