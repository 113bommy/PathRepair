#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, g, n, ans = 0;
  cin >> b >> g >> n;
  set<pair<int, int> > s;
  for (int i = 0; i <= b; i++) {
    int j = min(n - i, g);
    if (i + j != n || j < 0)
      continue;
    else {
      s.insert(make_pair(i, j));
    }
  }
  for (int i = 0; i <= g; i++) {
    int j = min(n - i, b);
    if (i + j != n || j < 0)
      continue;
    else {
      s.insert(make_pair(j, i));
    }
  }
  ans = s.size();
  cout << ans << endl;
}
