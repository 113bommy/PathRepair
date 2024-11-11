#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main() {
  memset(a, 0, sizeof(a));
  int n, p;
  cin >> n >> p;
  for (int i = 0; i < (int)(p); i++) {
    int a1, b1, d1;
    cin >> a1 >> b1 >> d1;
    a[a1][b1] = d1;
  }
  vector<pair<int, pair<int, int> > > ans;
  for (int i = (int)(1); i <= (int)(n); i++) {
    bool flag = true;
    for (int j = (int)(1); j <= (int)(n); j++)
      if (a[j][i] != 0) {
        flag = false;
        break;
      }
    if (flag == true) {
      int e = 1e9, v = i, index = -1;
      while (true) {
        bool f = false;
        for (int k = (int)(1); k <= (int)(n); k++)
          if (a[v][k] != 0) {
            e = min(e, a[v][k]);
            v = k;
            f = true;
            index = k;
            break;
          }
        if (f == false) {
          break;
        }
      }
      if (e != 1e9) {
        ans.push_back(make_pair(i, make_pair(index, e)));
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < (int)(ans.size()); i++)
    cout << ans[i].first << " " << ans[i].second.first << " "
         << ans[i].second.second << endl;
  cin.get();
  cin.get();
  return 0;
}
