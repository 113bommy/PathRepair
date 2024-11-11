#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > AdjList;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  int cost;
  cin >> cost;
  int a, b, c, d;
  for (int i = 0; i < 4; i++) {
    cin >> a >> b >> c >> d;
    if (min(a, b) + min(c, d) <= cost) {
      cout << i + 1 << ' ' << min(a, b) << ' ' << cost - (min(a, b)) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
