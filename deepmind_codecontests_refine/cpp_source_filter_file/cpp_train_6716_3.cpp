#include <bits/stdc++.h>
using namespace std;
long long n, m, k, s;
long long a[100100], b[100100];
vector<pair<long long, long long>> items;
bool func(long long d, long long burles_left, long long k) {
  long long mn_a = 1e9, mn_b = 1e9;
  for (int i = 0; i < d; ++i) mn_a = min(mn_a, a[i]);
  for (int i = 0; i < d; ++i) mn_b = min(mn_b, b[i]);
  vector<long long> price;
  for (int i = 0; i < m; ++i) {
    if (items[i].first == 1)
      price.push_back(mn_a * items[i].second);
    else
      price.push_back(mn_b * items[i].second);
  }
  sort(begin(price), end(price));
  for (int i = 0; i < m; ++i) {
    if (price[i] > burles_left) return false;
    burles_left -= price[i];
    if (i + 1 == k) return true;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> s;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  items.resize(m);
  for (int i = 0; i < m; ++i) cin >> items[i].first >> items[i].second;
  int lo = 0, hi = n, res = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (func(mid, s, k)) {
      hi = mid - 1;
      res = mid;
    } else
      lo = mid + 1;
  }
  if (res == -1) {
    cout << "-1" << endl;
    return 0;
  }
  long long mn_a = 1e9, mn_b = 1e9;
  long long mn_a_day, mn_b_day;
  for (int i = 0; i < res; ++i) {
    if (a[i] < mn_a) {
      mn_a = a[i];
      mn_a_day = i + 1;
    }
  }
  for (int i = 0; i < res; ++i) {
    if (b[i] < mn_b) {
      mn_b = b[i];
      mn_b_day = i + 1;
    }
  }
  vector<pair<long long, pair<int, int>>> price;
  for (int i = 0; i < m; ++i) {
    if (items[i].first == 1)
      price.push_back({mn_a * items[i].second, {i + 1, 1}});
    else
      price.push_back({mn_b * items[i].second, {i + 1, 2}});
  }
  sort(begin(price), end(price));
  cout << res << endl;
  for (int i = 0; i < k; ++i) {
    if (price[i].second.second == 1)
      cout << price[i].second.first << ' ' << mn_a_day << endl;
    else
      cout << price[i].second.first << ' ' << mn_b_day << endl;
  }
  return 0;
}
