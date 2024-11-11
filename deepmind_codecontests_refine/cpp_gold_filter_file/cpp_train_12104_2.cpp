#include <bits/stdc++.h>
using namespace std;
int mex(vector<int> a) {
  sort(a.begin(), a.end());
  int ret = 0;
  for (int(i) = 0; (i) < (((int)a.size())); ++(i)) {
    if (ret == a[i]) ret++;
  }
  return ret;
}
int nimsum(vector<int> a) {
  for (int(i) = (1); (i) < (((int)a.size())); ++(i)) a[0] ^= a[i];
  return a[0];
}
vector<string> f;
int dp[24][24][24][24];
int doit(int lr, int lc, int mr, int mc) {
  if (lr < 0 || lc < 0 || mr < 0 || mc < 0 || lr >= 22 || lc >= 22 ||
      mr >= 22 || mc >= 22)
    return 0;
  int& alias = dp[lr][lc][mr][mc];
  if (alias != -1) return alias;
  vector<int> grund;
  for (int(r) = (lr); (r) < (mr + 1); ++(r))
    for (int(c) = (lc); (c) < (mc + 1); ++(c))
      if (f[r][c] != 'I') {
        vector<int> nims;
        if (f[r][c] == 'R') {
          nims.push_back(doit(lr, lc, mr, c - 1));
          nims.push_back(doit(lr, c + 1, mr, mc));
        } else if (f[r][c] == 'L') {
          nims.push_back(doit(lr, lc, r - 1, mc));
          nims.push_back(doit(r + 1, lc, mr, mc));
        } else if (f[r][c] == 'X') {
          nims.push_back(doit(lr, lc, r - 1, c - 1));
          nims.push_back(doit(lr, c + 1, r - 1, mc));
          nims.push_back(doit(r + 1, lc, mr, c - 1));
          nims.push_back(doit(r + 1, c + 1, mr, mc));
        }
        int hasil = nimsum(nims);
        grund.push_back(hasil);
      }
  return alias = mex(grund);
}
int solve(vector<string> fuuu) {
  f = fuuu;
  int row = ((int)f.size());
  int col = ((int)f[0].size());
  for (int(i) = 0; (i) < (24); ++(i))
    for (int(j) = 0; (j) < (24); ++(j))
      for (int(k) = 0; (k) < (24); ++(k))
        for (int(l) = 0; (l) < (24); ++(l)) dp[i][j][k][l] = -1;
  return doit(0, 0, row - 1, col - 1);
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> f1(22, string(22, 'I'));
  vector<string> f2(22, string(22, 'I'));
  for (int(i) = 0; (i) < (n); ++(i)) {
    string str;
    cin >> str;
    for (int(j) = 0; (j) < (m); ++(j)) {
      int apub = i + j;
      int amib = i - j;
      if (apub % 2 == 0) {
        apub /= 2;
        amib /= 2;
        amib += 10;
        f1[apub][amib] = str[j];
      } else {
        apub--;
        apub /= 2;
        amib--;
        amib /= 2;
        amib += 11;
        f2[apub][amib] = str[j];
      }
    }
  }
  int yay = solve(f1) ^ solve(f2);
  if (yay) {
    cout << "WIN" << endl;
  } else {
    cout << "LOSE" << endl;
  }
}
