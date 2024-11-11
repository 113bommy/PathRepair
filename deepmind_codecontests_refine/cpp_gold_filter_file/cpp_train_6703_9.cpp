#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int fv[1010][1010], tw[1010][1010], a[1010][1010];
pair<int, int> d[1010][1010][2];
pair<int, int> pr[1010][1010][2];
int n;
void rest2(int idx, int idy) {
  cout << '1' << endl;
  string s;
  for (int i = 0; i < idx; i++) s += 'D';
  for (int i = 0; i < n - 1; i++) s += 'R';
  for (int i = 0; i < n - idx - 1; i++) s += 'D';
  cout << s << endl;
  exit(0);
}
void rest1() {
  int k = 0;
  cout << min(min(d[n - 1][n - 1][0].first, d[n - 1][n - 1][0].second),
              min(d[n - 1][n - 1][1].first, d[n - 1][n - 1][1].second))
       << endl;
  if (min(d[n - 1][n - 1][0].first, d[n - 1][n - 1][0].second) >
      min(d[n - 1][n - 1][1].first, d[n - 1][n - 1][1].second))
    k = 1;
  string s;
  int helpx = n - 1, helpy = n - 1;
  while (helpx >= 0) {
    if (pr[helpx][helpy][k].first < 0) break;
    if (pr[helpx][helpy][k] == make_pair(helpx, helpy - 1))
      s += 'R';
    else
      s += 'D';
    int helpx1 = helpx;
    helpx = pr[helpx][helpy][k].first;
    helpy = pr[helpx1][helpy][k].second;
  }
  for (int i = s.size() - 1; i >= 0; i--) printf("%c", s[i]);
}
int main() {
  cin >> n;
  for (int i = 0; i < 1010; i++)
    for (int j = 0; j < 1010; j++)
      for (int k = 0; k < 2; k++) {
        d[i][j][k] = make_pair(100500, 100500);
        pr[i][j][k] = make_pair(-5, -5);
      }
  bool q = false;
  int idx, idy;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      int b = a[i][j];
      if (b == 0) {
        q = true;
        idx = i;
        idy = j;
        fv[i][j] = tw[i][j] = 100500;
        continue;
      }
      while ((b % 2) == 0) {
        tw[i][j]++;
        b >>= 1;
      }
      b = a[i][j];
      while ((b % 5) == 0) {
        fv[i][j]++;
        b /= 5;
      }
    }
  d[0][0][0] = d[0][0][1] = make_pair(tw[0][0], fv[0][0]);
  for (int i = 1; i < n; i++) {
    pr[0][i][0] = pr[0][i][1] = make_pair(0, i - 1);
    d[0][i][0] = d[0][i][1] = make_pair(d[0][i - 1][0].first + tw[0][i],
                                        d[0][i - 1][0].second + fv[0][i]);
  }
  for (int i = 1; i < n; i++) {
    pr[i][0][0] = pr[i][0][1] = make_pair(i - 1, 0);
    d[i][0][0] = d[i][0][1] = make_pair(d[i - 1][0][0].first + tw[i][0],
                                        d[i - 1][0][0].second + fv[i][0]);
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) {
      if (d[i][j][0] > make_pair(d[i - 1][j][0].first + tw[i][j],
                                 d[i - 1][j][0].second + fv[i][j])) {
        d[i][j][0] = make_pair(d[i - 1][j][0].first + tw[i][j],
                               d[i - 1][j][0].second + fv[i][j]);
        pr[i][j][0] = make_pair(i - 1, j);
      }
      if (d[i][j][0] > make_pair(d[i][j - 1][0].first + tw[i][j],
                                 d[i][j - 1][0].second + fv[i][j])) {
        d[i][j][0] = make_pair(d[i][j - 1][0].first + tw[i][j],
                               d[i][j - 1][0].second + fv[i][j]);
        pr[i][j][0] = make_pair(i, j - 1);
      }
      if (d[i][j][1].second > d[i][j - 1][1].second + fv[i][j]) {
        d[i][j][1] = make_pair(d[i][j - 1][1].first + tw[i][j],
                               d[i][j - 1][1].second + fv[i][j]);
        pr[i][j][1] = make_pair(i, j - 1);
      }
      if (d[i][j][1].second > d[i - 1][j][1].second + fv[i][j]) {
        d[i][j][1] = make_pair(d[i - 1][j][1].first + tw[i][j],
                               d[i - 1][j][1].second + fv[i][j]);
        pr[i][j][1] = make_pair(i - 1, j);
      }
    }
  if (min(min(d[n - 1][n - 1][0].first, d[n - 1][n - 1][0].second),
          min(d[n - 1][n - 1][1].first, d[n - 1][n - 1][1].second)) > 1 &&
      q)
    rest2(idx, idy);
  else
    rest1();
  return 0;
}
