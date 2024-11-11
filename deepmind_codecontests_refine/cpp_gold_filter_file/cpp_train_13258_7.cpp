#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, n;
  cin >> s >> n;
  vector<pair<int, int>> A;
  while (n--) {
    int x, y;
    cin >> x >> y;
    A.push_back(make_pair(x, y));
  }
  int f = 0;
  sort(A.begin(), A.end());
  for (auto x : A) {
    if (s <= x.first) {
      f = 1;
      break;
    } else
      s = s + x.second;
  }
  f ? cout << "NO" : cout << "YES";
  return 0;
}
