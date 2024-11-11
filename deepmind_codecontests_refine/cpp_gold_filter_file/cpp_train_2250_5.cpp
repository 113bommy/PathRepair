#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int res[100000];
  memset(res, -1, sizeof(res));
  cin >> n;
  vector<pair<pair<long long, long long>, int> > v;
  for (int(i) = 0; (i) < (n); (i)++) {
    long long x, r;
    cin >> x >> r;
    v.push_back(pair<pair<long long, long long>, int>(
        pair<long long, long long>(x, r), i));
  }
  sort(v.begin(), v.end());
  int m;
  cin >> m;
  int ret = 0;
  for (int(i) = 0; (i) < (m); (i)++) {
    long long x, y;
    cin >> x >> y;
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (x < v[mid].first.first - v[mid].first.second) {
        r = mid - 1;
        continue;
      }
      if (x > v[mid].first.first + v[mid].first.second) {
        l = mid + 1;
        continue;
      }
      if ((x - v[mid].first.first) * (x - v[mid].first.first) + y * y <=
          v[mid].first.second * v[mid].first.second) {
        if (res[v[mid].second] == -1) {
          ret++;
          res[v[mid].second] = i + 1;
        }
      }
      if (mid > 0) {
        if ((x - v[mid - 1].first.first) * (x - v[mid - 1].first.first) +
                y * y <=
            v[mid - 1].first.second * v[mid - 1].first.second) {
          if (res[v[mid - 1].second] == -1) {
            ret++;
            res[v[mid - 1].second] = i + 1;
          }
        }
      }
      if (mid < n - 1) {
        if ((x - v[mid + 1].first.first) * (x - v[mid + 1].first.first) +
                y * y <=
            v[mid + 1].first.second * v[mid + 1].first.second) {
          if (res[v[mid + 1].second] == -1) {
            ret++;
            res[v[mid + 1].second] = i + 1;
          }
        }
      }
      break;
    }
  }
  cout << ret << endl;
  for (int(i) = 0; (i) < (n); (i)++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
