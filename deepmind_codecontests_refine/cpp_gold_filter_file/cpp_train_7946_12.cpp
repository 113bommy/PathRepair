#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<float, int> &a, const pair<float, int> &b) {
  return (a.second < b.second);
}
int main() {
  int n, t1, t2, v1, v2;
  double k;
  vector<pair<double, int> > result;
  cin >> n >> t1 >> t2 >> k;
  k = (100 - k) / 100;
  for (int i = 0; i < n; i++) {
    cin >> v1 >> v2;
    double ans1 = v1 * t1 * k + v2 * t2;
    double ans2 = v2 * t1 * k + v1 * t2;
    result.push_back(make_pair(max(ans1, ans2), i + 1));
  }
  sort(result.rbegin(), result.rend());
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    if (j < n && result[i].first == result[j].first) {
      while (j < n && result[i].first == result[j].first) j++;
      sort(result.begin() + i, result.begin() + j, sortbysec);
    }
    cout << result[i].second << " " << fixed << setprecision(2)
         << result[i].first << endl;
  }
  return 0;
}
