#include <bits/stdc++.h>
using namespace std;
int MaxVal = 2005;
long long tree[2009][2009];
int flag[2009], ar[2009][2009], TOT[2009], X1[2009], X2[2009], Y1[2009],
    Y2[2009];
long long ANS[2009];
vector<pair<int, int> > KEEP[2009];
vector<int> vec[2009];
void update(int x, int y, int val) {
  int y1;
  while (x <= MaxVal) {
    y1 = y;
    while (y1 <= MaxVal) {
      tree[x][y1] += val;
      y1 += (y1 & -y1);
    }
    x += (x & -x);
  }
}
int read(int x, int y) {
  long long sum = 0;
  int y1;
  while (x > 0) {
    y1 = y;
    while (y1 > 0) {
      sum += tree[x][y1];
      y1 -= (y1 & -y1);
    }
    x -= (x & -x);
  }
  return sum;
}
long long query(int x1, int y1, int x2, int y2) {
  return read(x2, y2) - read(x2, y1 - 1) - read(x1 - 1, y2) +
         read(x1 - 1, y1 - 1);
}
int main() {
  int i, j, k, l, n, m, q, now, inf, row, col, x, y, x1, x2, y1, y2, pos, siz;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= k; i++) {
    flag[i] = 1;
    scanf("%d", &TOT[i]);
    for (j = 1; j <= TOT[i]; j++) {
      scanf("%d%d", &x, &y);
      scanf("%d", &ar[x][y]);
      KEEP[i].push_back(make_pair(x, y));
    }
  }
  pos = 0;
  scanf("%d", &q);
  while (q--) {
    char aa[10];
    scanf("%s", aa);
    if (aa[0] == 'S') {
      scanf("%d", &i);
      flag[i] = !flag[i];
    } else {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      pos++;
      X1[pos] = x1;
      Y1[pos] = y1;
      X2[pos] = x2;
      Y2[pos] = y2;
      for (j = 1; j <= k; j++) {
        if (flag[j]) {
          vec[j].push_back(pos);
        }
      }
    }
  }
  for (i = 1; i <= k; i++) {
    for (j = 0; j < TOT[i]; j++) {
      update(KEEP[i][j].first, KEEP[i][j].second,
             ar[KEEP[i][j].first][KEEP[i][j].second]);
    }
    siz = vec[i].size();
    for (j = 0; j < siz; j++) {
      ANS[vec[i][j]] +=
          query(X1[vec[i][j]], Y1[vec[i][j]], X2[vec[i][j]], Y2[vec[i][j]]);
    }
    for (j = 0; j < TOT[i]; j++) {
      update(KEEP[i][j].first, KEEP[i][j].second,
             -ar[KEEP[i][j].first][KEEP[i][j].second]);
    }
  }
  for (i = 1; i <= pos; i++) cout << ANS[i] << endl;
}
