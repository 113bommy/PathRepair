#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int x, y;
  set<pair<pair<int, int>, int>> s[1001];
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    s[(x - 1) / 1000].insert(make_pair(make_pair(y, x), i));
  }
  for (int i = 0; i < 1001; i++)
    for (auto it : s[i]) {
      cout << it.second + 1 << " ";
    }
  return 0;
}
