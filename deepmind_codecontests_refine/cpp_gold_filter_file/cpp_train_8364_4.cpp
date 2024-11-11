#include <bits/stdc++.h>
using namespace std;
int dx[4];
int dy[4] = {0, 1, 2, 3};
int n, m;
int lth = 0;
char ch[20][20];
int ntc[20][20];
int gl;
int ob[300];
int used[300];
map<int, int> usedl[68005];
int sp[20];
int pst[20];
int pstl[20];
queue<int> q;
int cntt = 0;
int main() {
  int stt = 0;
  cin >> n >> m;
  memset(sp, -1, sizeof(sp));
  dx[0] = -m;
  dx[1] = -1;
  dx[2] = 1;
  dx[3] = m;
  memset(ob, 0, sizeof(ob));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ch[i][j];
      ntc[i][j] = i * m + j;
      if (ch[i][j] >= '0' && ch[i][j] <= '9') {
        sp[ch[i][j] - '0'] = ntc[i][j];
        pst[ch[i][j] - '0'] = ntc[i][j];
      } else if (ch[i][j] == '@') {
        gl = ntc[i][j];
      } else if (ch[i][j] == '#') {
        ob[ntc[i][j]] = 1;
      }
    }
  }
  lth = 1;
  for (int i = 2; i <= 10; i++) {
    if (sp[i] == -1) break;
    lth++;
  }
  for (int i = lth; i >= 2; i--) {
    stt = stt << 2;
    if (sp[i] - sp[i - 1] == m) {
      stt += 0;
    } else if (sp[i] - sp[i - 1] == 1) {
      stt += 1;
    } else if (sp[i] - sp[i - 1] == -m) {
      stt += 3;
    } else if (sp[i] - sp[i - 1] == -1) {
      stt += 2;
    }
  }
  q.push(stt);
  q.push(sp[1]);
  q.push(0);
  for (int i = 2; i <= lth; i++) {
    pst[i - 1] = pst[i];
  }
  int flg = 0;
  while (!q.empty()) {
    cntt++;
    int stt = q.front();
    q.pop();
    pst[1] = q.front();
    q.pop();
    int stp = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nhd = pst[1] + dx[i];
      if (i == 1 && (nhd + 1) % m == 0) continue;
      if (i == 2 && nhd % m == 0) continue;
      if (nhd > n * m - 1 || nhd < 0) continue;
      used[nhd] = 0;
    }
    for (int i = 2; i <= lth - 1; i++) {
      int sg = ((stt) >> ((i - 1 - 1) * 2));
      sg = sg & ((1 << 2) - 1);
      if (sg == 0) {
        pst[i] = pst[i - 1] + m;
      } else if (sg == 1) {
        pst[i] = pst[i - 1] + 1;
      } else if (sg == 3) {
        pst[i] = pst[i - 1] - m;
      } else if (sg == 2) {
        pst[i] = pst[i - 1] - 1;
      }
      used[pst[i]] = 1;
    }
    for (int i = 0; i < 4; i++) {
      int ff = 0;
      int sttt = stt;
      int nhd = pst[1] + dx[i];
      if (ff) continue;
      if (i == 1 && (nhd + 1) % m == 0) continue;
      if (i == 2 && nhd % m == 0) continue;
      sttt = sttt << 2;
      sttt &= ((1 << ((lth - 1) * 2)) - 1);
      sttt += i;
      if (nhd > n * m - 1 || nhd < 0 || ob[nhd] || used[nhd] ||
          usedl[sttt].count(nhd) == 1)
        continue;
      usedl[sttt][nhd] = 1;
      if (nhd == gl) {
        cout << stp + 1 << endl;
        flg = 1;
        break;
      }
      q.push(sttt);
      q.push(nhd);
      q.push(stp + 1);
    }
    if (flg) break;
  }
  if (!flg) cout << -1;
  return 0;
}
