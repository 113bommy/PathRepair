#include <bits/stdc++.h>
using namespace std;
map<string, int> ha;
string BD = "BERLAND", name[5];
int cpt[5][5], wb[5], ball[5];
int t_wb[5], t_ball[5], flg, diren, cnt[5], t_cnt[5];
int rk[5];
bool cmp(const int& a, const int& b) {
  if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
  if (wb[a] != wb[b]) return wb[a] > wb[b];
  if (ball[a] != ball[b]) return ball[a] > ball[b];
  return name[a] < name[b];
}
int find_diren() {
  int i;
  for (i = 2; i <= 4; i++)
    if (cpt[1][i] == 10) return i;
  return i;
}
int win(int X, int Y) {
  int i;
  memcpy(t_cnt, cnt, sizeof(cnt));
  memcpy(t_ball, ball, sizeof(ball));
  memcpy(t_wb, wb, sizeof(wb));
  cnt[1] += 3;
  wb[1] += X - Y;
  ball[1] += X;
  wb[diren] += Y - X;
  ball[diren] += Y;
  for (i = 1; i <= 4; i++) rk[i] = i;
  sort(rk + 1, rk + 5, cmp);
  memcpy(cnt, t_cnt, sizeof(cnt));
  memcpy(ball, t_ball, sizeof(ball));
  memcpy(wb, t_wb, sizeof(wb));
  for (i = 1; i <= 4; i++)
    if (rk[i] == 1) break;
  if (i <= 2) return 1;
  return 0;
}
void solv() {
  int i, dif, y, lmt_dif, lmt_x;
  for (i = 1; i <= 4; i++) rk[i] = i;
  sort(rk + 1, rk + 5, cmp);
  for (i = 1; i <= 4; i++)
    if (rk[i] == 1) break;
  if (i <= 2) {
    printf("1:0\n");
    return;
  } else if (cnt[rk[2]] - cnt[1] > 3) {
    printf("IMPOSSIBLE\n");
  }
  lmt_dif = 1;
  lmt_x = 1;
  for (i = 1; i <= 4; i++) {
    lmt_dif = max(lmt_dif, ball[i]);
    lmt_x = max(lmt_x, ball[i]);
  }
  lmt_dif += 5;
  lmt_x += 5;
  for (dif = 1; dif <= lmt_dif; dif++)
    for (y = 0; y <= lmt_x; y++)
      if (win(dif + y, y)) {
        printf("%d:%d\n", dif + y, y);
        return;
      }
}
int main() {
  int i, j, a, b;
  char T1[22], T2[22];
  string t1, t2;
  ha[BD] = ++flg;
  name[1] = BD;
  for (i = 1; i <= 4; i++)
    for (j = 1; j <= 4; j++) cpt[i][j] = 10;
  for (i = 0; i < 5; i++) {
    scanf("%s%s", T1, T2);
    scanf("%d:%d", &a, &b);
    t1 = T1;
    t2 = T2;
    if (ha[t1] == 0) {
      ha[t1] = ++flg;
      name[flg] = t1;
    }
    if (ha[t2] == 0) {
      ha[t2] = ++flg;
      name[flg] = t2;
    }
    wb[ha[t1]] += a - b;
    ball[ha[t1]] += a;
    wb[ha[t2]] += b - a;
    ball[ha[t2]] += b;
    if (a > b) {
      cnt[ha[t1]] += 3;
      cpt[ha[t1]][ha[t2]] = 1;
      cpt[ha[t2]][ha[t1]] = -1;
    } else if (a < b) {
      cnt[ha[t2]] += 3;
      cpt[ha[t1]][ha[t2]] = -1;
      cpt[ha[t2]][ha[t1]] = 1;
    } else {
      cnt[ha[t1]]++;
      cnt[ha[t2]]++;
      cpt[ha[t1]][ha[t2]] = 0;
      cpt[ha[t2]][ha[t1]] = 0;
    }
  }
  diren = find_diren();
  solv();
  return 0;
}
