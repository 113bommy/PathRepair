#include <bits/stdc++.h>
using namespace std;
char _;
const int maxN = 100 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
const int base = 701;
const int SQ = 600;
const int maxL = 20;
char a[maxN][maxN];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  if (m == 1) {
    cout << "Second" << endl;
    return 0;
  }
  if (m == 2) {
    int ted1 = 0, ted2 = 0;
    for (int i = 0; i < n; i++) {
      int p1 = 0, p2 = 0;
      for (int j = 0; j < m; j++)
        if (a[i][j] == 'G')
          p1++;
        else if (a[i][j] == 'R')
          p2++;
      if (p1 == 1 && p2 == 0) ted1++;
      if (p1 == 0 && p2 == 1) ted2++;
    }
    if (ted1 == 0)
      cout << "Second" << endl;
    else if (ted2 == 0)
      cout << "First" << endl;
    else
      cout << "Draw" << endl;
    return 0;
  }
  vector<int> v;
  int ted1 = 0, ted2 = 0;
  for (int i = 0; i < n; i++) {
    int p1 = 0, p2 = 0;
    for (int j = 0; j < m; j++)
      if (a[i][j] == 'G')
        p1++;
      else if (a[i][j] == 'R')
        p2++;
    if (p1 + p2) {
      if (p1 == 0)
        ted2++;
      else if (p2 == 0)
        ted1++;
      else {
        vector<int> pp;
        for (int j = 0; j < m; j++)
          if (a[i][j] != '-') pp.push_back(j);
        v.push_back(pp[1] - pp[0]);
      }
    }
  }
  if (ted1 || ted2) {
    if (ted1 && ted2)
      cout << "Draw" << endl;
    else if (ted1)
      cout << "First" << endl;
    else
      cout << "Second" << endl;
    return 0;
  }
  for (int i = 0; i < 10; i++) {
    int ted = 0;
    for (int j = 0; j < (int)v.size(); j++) ted += (v[j] >> i & 1);
    if (ted % (k + 1)) {
      cout << "First" << endl;
      return 0;
    }
  }
  cout << "Second" << endl;
  return 0;
}
