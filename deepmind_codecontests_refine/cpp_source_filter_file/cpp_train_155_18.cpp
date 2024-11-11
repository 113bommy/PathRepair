#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (k >= n && n > 4) {
    vector<int> path;
    path.push_back(a);
    path.push_back(c);
    for (int i = 1; i <= n; i++) {
      if (i != a && i != b && i != c && i != d) path.push_back(i);
    }
    path.push_back(d);
    path.push_back(b);
    if (path.size() > k) {
      cout << -1;
      exit(0);
    }
    for (int i = 0; i < n; i++) {
      cout << path[i] << ' ';
    }
    cout << '\n';
    path.clear();
    path.push_back(c);
    path.push_back(a);
    for (int i = 1; i <= n; i++) {
      if (i != c && i != d && i != a && i != b) path.push_back(i);
    }
    path.push_back(b);
    path.push_back(d);
    for (int i = 0; i < n; i++) {
      cout << path[i] << ' ';
    }
  } else
    cout << -1;
  return 0;
}
