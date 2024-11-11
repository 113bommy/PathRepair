#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
const int maxlen = 1e5 + 10;
const long long mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > a;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back(make_pair(x, x + y));
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int l1 = a[i].first, r1 = a[i].second;
      int l2 = a[j].first, r2 = a[j].second;
      int k1 = a[i].first < a[i].second, k2 = a[j].first < a[j].second;
      if (l1 > r1) swap(l1, r1);
      if (l2 > r2) swap(l2, r2);
      if (r1 < l2 || l1 >= r2) continue;
      if (k1 == k2 && (r2 == r1 && l2 <= l1 || l1 == l2 && r2 <= r1))
        cnt += 2;
      else if (k1 == k2 && (r1 < r2 && l1 < l2 || r1 > r2 && l1 > l2))
        cnt += 2;
      else
        cnt += 1;
    }
  cout << cnt;
  return 0;
}
