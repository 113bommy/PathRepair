#include <bits/stdc++.h>
using namespace std;
int mp[222][222];
pair<int, int> a[5], b[5];
int main() {
  bool flag = 0;
  for (int i = 0; i < 4; i++) cin >> a[i].first >> a[i].second;
  for (int i = 0; i < 4; i++) cin >> b[i].first >> b[i].second;
  for (int i = 0; i < 4; i++) {
    a[i].first += 100;
    a[i].second += 100;
    b[i].first += 100;
    b[i].second += 100;
  }
  sort(a, a + 4);
  sort(b, b + 4);
  memset(mp, 0, sizeof mp);
  for (int i = a[0].first; i <= a[3].first; i++) {
    for (int j = a[0].second; j <= a[3].second; j++) {
      mp[i][j]++;
    }
  }
  for (int i = b[0].first; i <= b[2].first; i++) {
    int n = i, m = b[0].first + b[0].second - i;
    for (int j = b[0].second; j <= b[2].second; j++) {
      mp[n][m]++;
      if (mp[n][m] >= 2) {
        flag = 1;
        break;
      }
      n++;
      m++;
    }
    if (flag) break;
  }
  if (flag)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}
