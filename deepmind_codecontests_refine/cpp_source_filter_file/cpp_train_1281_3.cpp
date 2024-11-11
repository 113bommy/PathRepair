#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  pair<long long int, long long int> a[4][2];
  map<pair<long long int, long long int>, int> mp;
  bool f = 1;
  long long int max1 = 1e10, min1 = -1e10;
  int cnt = 0;
  int d[2];
  for (int i = 0; i < 4; i++) {
    cin >> a[i][0].first >> a[i][0].second >> a[i][1].first >> a[i][1].second;
    mp[a[i][0]]++;
    mp[a[i][1]]++;
    if (a[i][0].second == a[i][1].second) {
      cnt++;
      if (cnt == 1) d[0] = a[i][0].second;
      if (cnt == 2) d[1] = a[i][0].second;
      if (max1 == 1e10 && min1 == -1e10) {
        max1 = max(a[i][0].first, a[i][1].first);
        min1 = min(a[i][0].first, a[i][1].first);
      } else {
        long long int a1, b1;
        a1 = max(a[i][0].first, a[i][1].first);
        b1 = min(a[i][0].first, a[i][1].first);
        if (a1 != max1 || b1 != min1) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  if (cnt != 2)
    cout << "NO" << endl;
  else {
    for (int i = 0; i < 4; i++) {
      if (d[0] == a[i][0].first || d[1] == a[i][1].first) {
        if (a[i][0].first == a[i][1].first) {
          long long int a1, b1;
          a1 = max(a[i][0].second, a[i][1].second);
          b1 = min(a[i][0].second, a[i][1].second);
          if (a1 == max(d[0], d[1]) && b1 == min(d[0], d[1])) cnt++;
        }
      }
    }
    if (cnt == 4 && (abs(d[0] - d[1]) * abs(max1 - min1)) > 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
