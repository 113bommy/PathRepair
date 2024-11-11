#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, n;
  cin >> s >> n;
  int x, y;
  pair<int, int> p[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    if (s >= p[i].first) {
      s += p[i].second;
    } else
      return cout << "NO" << endl, 0;
  }
  cout << "YES" << endl;
  return 0;
}
