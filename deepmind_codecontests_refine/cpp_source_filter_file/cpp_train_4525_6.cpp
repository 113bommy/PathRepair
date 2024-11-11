#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i, j, t = 0, s = 0, p = 0;
  pair<int, int> y[2001];
  map<int, int> x;
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> a;
    y[i].first = a;
    y[i].second = i + 1;
    x[a]++;
    if (x[a] >= 3) t = 1;
    if (x[a] == 2) s++;
  }
  sort(y, y + n);
  if (t == 1 || s >= 2) {
    cout << "YES" << endl;
    for (i = 0; i < n; ++i) cout << y[i].second << " ";
    cout << endl;
    for (i = 0; i < n; ++i) {
      if (y[i].first == y[i + 1].first && p == 0) {
        swap(y[i], y[i + 1]);
        p = 1;
      }
      cout << y[i].second << " ";
    }
    cout << endl;
    p = 0;
    for (i = 0; i < n; ++i) {
      if (y[i].first == y[i + 1].first && p == 2) {
        swap(y[i], y[i + 1]);
        p++;
      }
      cout << y[i].second << " ";
    }
    cout << endl;
  } else
    cout << "NO";
  return 0;
}
