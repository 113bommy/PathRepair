#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, y = 0;
  cin >> n;
  pair<int, int> p[n];
  for (i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  for (i = 0; i < n; i++)
    if (p[i].second > p[i + 1].second) {
      cout << "Happy Alex";
      y = 1;
      break;
    }
  if (y == 0) cout << "Poor Alex";
}
