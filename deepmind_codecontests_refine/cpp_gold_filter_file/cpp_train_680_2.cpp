#include <bits/stdc++.h>
using namespace std;
inline int rint() {
  int a;
  scanf("%d", &a);
  return a;
}
inline long long rll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
inline double rdouble() {
  double a;
  scanf("%lf", &a);
  return a;
}
int main() {
  int n = rint();
  int a[505];
  for (int i = 1; i <= n; i++) a[i] = rint();
  int m = rint();
  int b[505];
  for (int i = 1; i <= m; i++) b[i] = rint();
  long long s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++) s1 += a[i];
  for (int i = 1; i <= m; i++) s2 += b[i];
  if (s1 != s2) return puts("NO");
  vector<int> v[505];
  int start[505];
  int now = 1;
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    start[i] = now;
    while (sum < b[i]) {
      v[i].push_back(a[now]);
      sum += a[now++];
    }
    if (sum > b[i]) return puts("NO");
    sum = 0;
  }
  vector<pair<int, char>> res;
  for (int i = m; i >= 1; i--) {
    if (v[i].size() == 1) continue;
    int maxx = 0;
    for (int j = 0; j < v[i].size(); j++) maxx = max(maxx, v[i][j]);
    int jb = -1;
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == maxx) {
        if (j == 0)
          if (v[i][j + 1] != maxx) {
            jb = j;
            break;
          }
        if (j == v[i].size() - 1)
          if (v[i][j - 1] != maxx) {
            jb = j;
            break;
          }
        if (j != 0 && j != v[i].size() - 1)
          if (v[i][j + 1] != maxx || v[i][j - 1] != maxx) {
            jb = j;
            break;
          }
      }
    }
    if (jb == -1) return puts("NO");
    if (jb != v[i].size() - 1 && v[i][jb] != v[i][jb + 1]) {
      for (int j = 0; j < v[i].size() - 1 - (jb + 1) + 1; j++)
        res.push_back(make_pair(jb + start[i], 'R'));
      while (jb != 0) {
        res.push_back(make_pair(jb + start[i], 'L'));
        jb--;
      }
    } else {
      res.push_back(make_pair(jb + start[i], 'L'));
      for (int j = 0; j < v[i].size() - 1 - (jb + 1) + 1; j++)
        res.push_back(make_pair(jb - 1 + start[i], 'R'));
      jb--;
      while (jb != 0) {
        res.push_back(make_pair(jb + start[i], 'L'));
        jb--;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < res.size(); i++)
    cout << res[i].first << " " << res[i].second << endl;
  return 0;
}
