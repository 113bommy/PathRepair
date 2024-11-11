#include <bits/stdc++.h>
using namespace std;
const int MOD = 12345;
const int STD_SIZE = 130;
int msize;
struct Matrix {
  int mat[STD_SIZE][STD_SIZE];
  Matrix() { memset(mat, 0, sizeof mat); }
  inline Matrix operator*(const Matrix& b) {
    Matrix ret;
    for (int i = 0; i < msize; i++)
      for (int j = 0; j < msize; j++)
        for (int k = 0; k < msize; k++)
          ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * b.mat[k][j]) % MOD;
    return ret;
  }
};
map<char, vector<int> > mp;
int lvl[30], prd[30];
bool vis[STD_SIZE], nvalid[STD_SIZE];
int main() {
  long long N;
  int C;
  cin >> N;
  scanf("%d", &C);
  for (int i = 1; i <= C; i++) {
    char buf[10];
    int val;
    scanf("%s%d", buf, &val);
    mp[buf[0]].push_back(val);
  }
  for (char chr = 'A'; chr <= 'Z'; chr++) {
    vector<int>& tmp = mp[chr];
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    lvl[chr - 'A' + 1] = 1;
    for (int i = 0; i < (int)tmp.size(); i++)
      lvl[chr - 'A' + 1] = lvl[chr - 'A' + 1] * tmp[i];
  }
  prd[0] = lvl[0] = 1;
  for (int i = 1; i <= 26; i++) prd[i] = prd[i - 1] * lvl[i];
  msize = prd[26];
  Matrix unit, mfac;
  for (int i = 0; i < msize; i++) unit.mat[i][i] = 1;
  for (int cur = 0; cur < msize; cur++) {
    for (int nxt = 0; nxt < 26; nxt++) {
      if (mp['A' + nxt].size() == 0) continue;
      int cbit = cur / prd[nxt] % lvl[nxt + 1];
      int nbit = (cbit + 1) % lvl[nxt + 1];
      int delta = (nbit - cbit) * prd[nxt];
      mfac.mat[cur][cur + delta]++;
    }
  }
  while (N) {
    if (N & 1) unit = unit * mfac;
    mfac = mfac * mfac;
    N >>= 1;
  }
  int ans = 0;
  for (int chr = 0; chr < 26; chr++) {
    vector<int>& tmp = mp['A' + chr];
    if (tmp.size() == 0) continue;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < (int)tmp.size(); i++)
      for (int j = 0; j < lvl[1 + chr]; j += tmp[i]) vis[j] = true;
    for (int i = 0; i < msize; i++) {
      int cbit = i / prd[chr] % lvl[chr + 1];
      if (!vis[cbit]) nvalid[i] = true;
    }
  }
  for (int i = 0; i < msize; i++) {
    if (nvalid[i]) continue;
    ans = (ans + unit.mat[0][i]);
  }
  cout << ans % MOD << '\n';
}
