#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int vi(0), o[N], ob[N];
double v[N][N], dis[N];
bool cmp(int ca, int cb) {
  return (dis[ca] > dis[cb]) || (dis[ca] == dis[cb] && ca < cb);
}
double Dis(int da, int db) {
  return sqrt((v[da][1] - v[db][1]) * (v[da][1] - v[db][1]) +
              (v[da][2] - v[db][2]) * (v[da][2] - v[db][2]) +
              (v[da][3] - v[db][3]) * (v[da][3] - v[db][3]));
}
inline void COME() {
  register int i, j;
  ;
  for (i = 1; i <= 8; ++i) o[i] = i;
  for (i = 1; i <= 8; ++i) dis[i] = Dis(1, i);
  sort(o + 1, o + 9, cmp);
  for (i = 1; i <= 8; ++i)
    for (j = 1; j <= 8; ++j)
      if (i != j)
        if (v[i][1] == v[j][1] && v[i][2] == v[j][2] && v[i][3] == v[j][3])
          return;
  if (dis[o[1]] != dis[o[2]] && dis[o[2]] == dis[o[3]] &&
      dis[o[3]] == dis[o[4]])
    if (dis[o[4]] != dis[o[5]] && dis[o[5]] == dis[o[6]] &&
        dis[o[6]] == dis[o[7]]) {
      for (i = 1; i <= 8; ++i) ob[i] = i;
      for (i = 1; i <= 8; ++i) dis[i] = Dis(o[1], i);
      sort(ob + 1, ob + 9, cmp);
      if (ob[1] == o[8] && o[2] == ob[5] && o[3] == ob[6] && o[4] == ob[7])
        if (o[1] == ob[8] && ob[2] == o[5] && ob[3] == o[6] && ob[4] == o[7]) {
          vi = 1;
          printf("YES\n");
          for (i = 1; i <= 8; ++i) {
            for (j = 1; j <= 3; ++j) printf("%.0lf ", v[i][j]);
            printf("\n");
          }
        }
    }
}
inline void DFS(int o) {
  register int i, j;
  ;
  if (o == 9) {
    COME();
    return;
  }
  for (i = 1; i <= 2; ++i)
    for (j = i + 1; j <= 3; ++j)
      if (!vi) {
        swap(v[o][i], v[o][j]), DFS(o + 1);
        swap(v[o][2], v[o][3]), DFS(o + 1);
        swap(v[o][2], v[o][3]), swap(v[o][i], v[o][j]);
      }
}
int main() {
  register int i, j;
  ;
  for (i = 1; i <= 8; ++i)
    for (j = 1; j <= 3; ++j) scanf("%lf", &v[i][j]);
  DFS(1);
  if (!vi) printf("NO\n");
  return 0;
}
