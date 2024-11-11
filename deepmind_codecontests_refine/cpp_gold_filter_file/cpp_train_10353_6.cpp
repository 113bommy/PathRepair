#include <bits/stdc++.h>
using namespace std;
int main() {
  long a, b, cnt, d, n, p, ta, i, j;
  vector<long> v[60], v1;
  while (cin >> n >> ta) {
    cnt = 0;
    v1.clear();
    for (i = 0; i < 55; i++) v[i].clear();
    for (i = 0; i < n; i++) {
      cin >> p;
      for (j = 0; j < p; j++) {
        cin >> a;
        v[i].push_back(a);
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < v[i].size(); j++) {
        if (v[i][j] < ta) {
          cnt++;
          v1.push_back(i + 1);
          break;
        }
      }
    }
    cout << cnt << endl;
    for (i = 0; i < v1.size(); i++) {
      if (i != v1.size() - 1)
        cout << v1[i] << " ";
      else
        cout << v1[i] << endl;
    }
  }
  return 0;
}
