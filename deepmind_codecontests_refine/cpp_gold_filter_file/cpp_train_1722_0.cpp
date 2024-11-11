#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[1009];
int main() {
  int n, k, i, j, l, mini = 0, maxo = 2000;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i].first;
  }
  for (i = 0; i < n; i++) {
    cin >> a[i].second;
  }
  int c = 0;
  while (mini < maxo) {
    int mid = (mini + maxo + 1) / 2;
    int mag = k;
    int st = 0;
    c++;
    for (i = 0; i < n; i++) {
      int div = (a[i].second / a[i].first);
      if (div < mid) {
        int req = mid * a[i].first;
        int diff = req - a[i].second;
        if (diff <= mag) {
          mag -= diff;
        } else {
          st = 1;
          break;
        }
      }
    }
    if (st == 1) {
      maxo = mid - 1;
    } else {
      mini = mid;
    }
  }
  cout << mini;
}
