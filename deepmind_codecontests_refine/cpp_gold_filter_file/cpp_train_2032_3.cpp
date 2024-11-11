#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e3 + 10;
const long long INF = 1e18;
long long n, m, a[MAX_N], b[MAX_N], v0, v1, v2, ans1x, ans1y, sum1, sum2;
vector<pair<int, int> > ans;
vector<long long> v;
map<long long, pair<int, int> > MAP;
long long calv0() { return abs(sum1 - sum2); }
long long calv1() {
  long long MIN = INF;
  long long tmp1, tmp2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      tmp1 = sum1 - a[i] + b[j];
      tmp2 = sum2 - b[j] + a[i];
      if (abs(tmp1 - tmp2) < MIN) {
        MIN = abs(tmp1 - tmp2);
        ans1x = i;
        ans1y = j;
      }
    }
  }
  return MIN;
}
long long calv2() {
  for (int i = 1; i <= m; i++)
    for (int j = i + 1; j <= m; j++) {
      v.push_back(b[i] + b[j]);
      MAP[b[i] + b[j]] = make_pair(i, j);
    }
  sort(v.begin(), v.end());
  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
  long long MIN = INF;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      long long f = a[i] + a[j];
      vector<long long>::iterator it =
          lower_bound(v.begin(), v.end(), floor((sum2 + 2 * f - sum1) / 2.0));
      if (it == v.end()) {
        it--;
        long long p = *it;
        long long tmp1 = sum1 - f + p;
        long long tmp2 = sum2 + f - p;
        if (abs(tmp1 - tmp2) < MIN) {
          MIN = abs(tmp1 - tmp2);
          ans.clear();
          pair<int, int> TMP = MAP[p];
          ans.push_back(make_pair(i, TMP.first));
          ans.push_back(make_pair(j, TMP.second));
        }
      } else if (it == v.begin()) {
        long long p = *it;
        long long tmp1 = sum1 - f + p;
        long long tmp2 = sum2 + f - p;
        if (abs(tmp1 - tmp2) < MIN) {
          MIN = abs(tmp1 - tmp2);
          ans.clear();
          pair<int, int> TMP = MAP[p];
          ans.push_back(make_pair(i, TMP.first));
          ans.push_back(make_pair(j, TMP.second));
        }
      } else {
        long long p = *it;
        long long tmp1 = sum1 - f + p;
        long long tmp2 = sum2 + f - p;
        if (abs(tmp1 - tmp2) < MIN) {
          MIN = abs(tmp1 - tmp2);
          ans.clear();
          pair<int, int> TMP = MAP[p];
          ans.push_back(make_pair(i, TMP.first));
          ans.push_back(make_pair(j, TMP.second));
        }
        it--;
        p = *it;
        tmp1 = sum1 - f + p;
        tmp2 = sum2 + f - p;
        if (abs(tmp1 - tmp2) < MIN) {
          MIN = abs(tmp1 - tmp2);
          ans.clear();
          pair<int, int> TMP = MAP[p];
          ans.push_back(make_pair(i, TMP.first));
          ans.push_back(make_pair(j, TMP.second));
        }
      }
    }
  }
  return MIN;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum1 += a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    sum2 += b[i];
  }
  long long x = calv0();
  long long y = calv1();
  if (n == 1 || m == 1) {
    if (x <= y) {
      cout << x << endl << 0 << endl;
      return 0;
    }
    if (y < x) {
      cout << y << endl << 1 << endl;
      cout << ans1x << " " << ans1y << endl;
      return 0;
    }
  }
  long long z = calv2();
  if (x <= y and x <= z) {
    cout << x << endl << 0 << endl;
    return 0;
  }
  if (y <= x and y <= z) {
    cout << y << endl << 1 << endl;
    cout << ans1x << " " << ans1y << endl;
    return 0;
  }
  cout << z << endl << 2 << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
