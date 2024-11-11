#include <bits/stdc++.h>
using namespace std;
int n, x, y;
bool was;
pair<int, int> a[5000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    was = false;
    for (int j = 1; j < i; j++) {
      if (a[j].first <= x && a[j].second >= x) was = true;
      if (a[j].first >= x && a[j].second <= x + y - 1) was = true;
      if (a[j].first <= x + y - 1 && a[j].second >= x + y - 1) was = true;
    }
    if (was == false) {
      a[i].first = x;
      a[i].second = x + y - 1;
      cout << x << ' ' << x + y - 1 << endl;
      sort(a, a + i + 1);
    } else {
      for (int g = 0; g < i; g++) {
        was = false;
        for (int j = 1; j < i; j++) {
          if (a[j].first <= a[g].second + 1 && a[j].second >= a[g].second + 1)
            was = true;
          if (a[j].first >= a[g].second && a[j].second <= a[g].second + y)
            was = true;
          if (a[j].first <= a[g].second + y && a[j].second >= a[g].second + y)
            was = true;
        }
        if (was == false) {
          a[i].first = a[g].second + 1;
          a[i].second = a[g].second + y;
          cout << a[g].second + 1 << ' ' << a[g].second + y << endl;
          sort(a, a + i + 1);
          break;
        }
      }
    }
  }
  return 0;
}
