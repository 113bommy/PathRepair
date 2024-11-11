#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
vector<int> lc[300010];
char toCout[] = {'A', 'G', 'C', 'T'};
int forCol[300010][4][2], forRow[300010][4][2];
int main() {
  mp['A'] = 0;
  mp['G'] = 1;
  mp['C'] = 2;
  mp['T'] = 3;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char a;
      cin >> a;
      lc[i].push_back(mp[a]);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) forCol[i][lc[j][i]][j % 2]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) forRow[i][lc[i][j]][j % 2]++;
  }
  int row = 0;
  vector<int> ele, good;
  ele.push_back(0);
  ele.push_back(1);
  ele.push_back(2);
  ele.push_back(3);
  int realAns = 0;
  do {
    int var = ele[0], var1 = ele[1], var2 = ele[2], var3 = ele[3];
    int ans1 = forCol[0][var][0] + forCol[0][var2][1] + forCol[1][var1][0] +
               forCol[1][var3][1];
    int ans2 = forRow[0][var][0] + forRow[0][var1][1] + forRow[1][var2][0] +
               forRow[1][var3][1];
    for (int i = 2; i < m; i++) {
      if (i % 2 == 0)
        ans1 += max(forCol[i][var][0] + forCol[i][var2][1],
                    forCol[i][var][1] + forCol[i][var2][0]);
      else
        ans1 += max(forCol[i][var1][0] + forCol[i][var3][1],
                    forCol[i][var1][1] + forCol[i][var3][0]);
    }
    for (int i = 2; i < n; i++) {
      if (i % 2 == 0)
        ans2 += max(forRow[i][var][0] + forRow[i][var1][1],
                    forRow[i][var][1] + forRow[i][var1][0]);
      else
        ans2 += max(forRow[i][var2][0] + forRow[i][var3][1],
                    forRow[i][var2][1] + forRow[i][var3][0]);
    }
    if (max(ans1, ans2) > realAns) {
      if (ans1 > ans2)
        row = 0;
      else
        row = 1;
      good = vector<int>();
      good.push_back(var);
      good.push_back(var1);
      good.push_back(var2);
      good.push_back(var3);
      realAns = max(ans1, ans2);
    }
  } while (next_permutation(ele.begin(), ele.end()));
  if (row) {
    for (int i = 0; i < m; i++) {
      if (i % 2 == 0)
        cout << toCout[good[0]];
      else
        cout << toCout[good[1]];
    }
    cout << '\n';
    for (int i = 0; i < m; i++) {
      if (i % 2 == 0)
        cout << toCout[good[2]];
      else
        cout << toCout[good[3]];
    }
    cout << '\n';
    for (int i = 2; i < n; i++) {
      int add = 0;
      if (i % 2) add = 2;
      int var, var1;
      if (forRow[i][good[0 + add]][0] + forRow[i][good[1 + add]][1] >
          forRow[i][good[0 + add]][1] + forRow[i][good[1 + add]][0])
        var = good[0 + add], var1 = good[1 + add];
      else
        var = good[1 + add], var1 = good[0 + add];
      for (int j = 0; j < m; j++) {
        if (j % 2 == 0)
          cout << toCout[var];
        else
          cout << toCout[var1];
      }
      cout << '\n';
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        cout << toCout[good[0]] << toCout[good[1]];
        for (int j = 2; j < m; j++) {
          if (j % 2 == 0) {
            if (forCol[j][good[0]][0] + forCol[j][good[2]][1] >
                forCol[j][good[0]][1] + forCol[j][good[2]][0])
              cout << toCout[good[0]];
            else
              cout << toCout[good[2]];
          } else {
            if (forCol[j][good[1]][0] + forCol[j][good[3]][1] >
                forCol[j][good[1]][1] + forCol[j][good[3]][0])
              cout << toCout[good[1]];
            else
              cout << toCout[good[3]];
          }
        }
        cout << '\n';
      } else {
        cout << toCout[good[2]] << toCout[good[3]];
        for (int j = 2; j < m; j++) {
          if (j % 2 == 0) {
            if (forCol[j][good[0]][0] + forCol[j][good[2]][1] >
                forCol[j][good[0]][1] + forCol[j][good[2]][0])
              cout << toCout[good[2]];
            else
              cout << toCout[good[0]];
          } else {
            if (forCol[j][good[1]][0] + forCol[j][good[3]][1] >
                forCol[j][good[1]][1] + forCol[j][good[3]][0])
              cout << toCout[good[3]];
            else
              cout << toCout[good[1]];
          }
        }
        cout << '\n';
      }
    }
  }
}
