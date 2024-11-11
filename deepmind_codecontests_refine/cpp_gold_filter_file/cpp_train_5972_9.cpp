#include <bits/stdc++.h>
using namespace std;
int a[105][105], c[105], r[105];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      c[j] += a[i][j];
      r[i] += a[i][j];
    }
  int co = 0;
  set<int> sc, sr;
  set<int>::iterator it;
  while (co <= 10) {
    for (int i = 1; i <= n; i++)
      if (r[i] < 0) {
        if (sr.find(i) != sr.end())
          sr.erase(sr.find(i));
        else
          sr.insert(i);
        r[i] = -r[i];
        for (int j = 1; j <= m; j++) c[j] -= 2 * a[i][j];
        for (int j = 1; j <= m; j++) a[i][j] = -a[i][j];
      }
    for (int j = 1; j <= m; j++)
      if (c[j] < 0) {
        if (sc.find(j) != sc.end())
          sc.erase(sc.find(j));
        else
          sc.insert(j);
        c[j] = -c[j];
        for (int i = 1; i <= n; i++) r[i] -= 2 * a[i][j];
        for (int i = 1; i <= n; i++) a[i][j] = -a[i][j];
      }
    co++;
  }
  cout << sr.size() << " ";
  for (it = sr.begin(); it != sr.end(); it++) cout << *it << " ";
  cout << endl;
  cout << sc.size() << " ";
  for (it = sc.begin(); it != sc.end(); it++) cout << *it << " ";
  return 0;
}
