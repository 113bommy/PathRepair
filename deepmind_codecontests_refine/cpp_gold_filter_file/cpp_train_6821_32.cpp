#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> > s, t;
int a[6000][6000];
int main() {
  cin >> n >> m >> k;
  s.resize(n);
  t.resize(m);
  for (int i = 0; i < k; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      x--;
      s[x] = make_pair(y, i);
    } else {
      int x, y;
      cin >> x >> y;
      x--;
      t[x] = make_pair(y, i);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i].first == 0 && t[j].first == 0)
        a[i][j] = 0;
      else if (s[i].first == 0)
        a[i][j] = t[j].first;
      else if (t[j].first == 0)
        a[i][j] = s[i].first;
      else {
        int z;
        if (s[i].second > t[j].second)
          z = s[i].first;
        else
          z = t[j].first;
        a[i][j] = z;
      }
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}
