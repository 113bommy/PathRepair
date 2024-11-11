#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, char> > res;
int main() {
  long long x, y;
  cin >> x >> y;
  while (x && y) {
    if (x > y) {
      res.push_back({x / y, 'A'});
      x %= y;
    } else if (x < y) {
      res.push_back({y / x, 'B'});
      y %= x;
    } else {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  if (x + y > 1) {
    cout << "Impossible" << endl;
    return 0;
  }
  for (int i = 0; i < res.size(); i++) {
    if (i == res.size() - 1) res[i].first--;
    printf("%I64d%c", res[i].first, res[i].second);
  }
  printf("\n");
}
