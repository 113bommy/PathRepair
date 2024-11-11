#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
int matrix[22][22];
int mas[22];
int matrix1[22][22];
int matrix2[22][22];
int best = 0;
int minv[22];
bool used[22];
int u[22];
int v[22];
int p[22];
int way[22];
int getresult(int n) {
  int res = 0;
  for (int i = 0; i <= n; i++) u[i] = 0;
  for (int i = 0; i <= n; i++) v[i] = 0;
  for (int i = 0; i <= n; i++) p[i] = 0;
  for (int i = 0; i <= n; i++) way[i] = 0;
  int m = n;
  const int INF = 1e9;
  for (int i = 1; i <= n; ++i) {
    p[0] = i;
    int j0 = 0;
    for (int x = 0; x <= m; x++) minv[x] = INF;
    for (int x = 0; x <= m; x++) used[x] = false;
    do {
      used[j0] = true;
      int i0 = p[j0], delta = INF, j1;
      for (int j = 1; j <= m; ++j)
        if (!used[j]) {
          int cur = matrix[i0][j] - u[i0] - v[j];
          if (cur < minv[j]) minv[j] = cur, way[j] = j0;
          if (minv[j] < delta) delta = minv[j], j1 = j;
        }
      for (int j = 0; j <= m; ++j)
        if (used[j])
          u[p[j]] += delta, v[j] -= delta;
        else
          minv[j] -= delta;
      j0 = j1;
    } while (p[j0] != 0);
    do {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while (j0);
  }
  return -v[0];
}
int line1max[22];
int line2max[22];
int colmax[22];
int rr[22];
bool stop = false;
int itt = 0;
int go(int pos, int N, int N2, int cnt1 = 0, int cnt2 = 0) {
  if (stop) return 0;
  if (pos == N) {
    int res = 0;
    int maxres = 0;
    int maxres2 = 0;
    for (int i = 0; i < N; i++) colmax[i] = 0;
    for (int i = 0; i < N; i++) {
      if (mas[i] == 1) {
        for (int j = 0; j < N; j++)
          matrix[i + 1][j + 1] = -matrix1[i][j],
                            colmax[j] = max(colmax[j], matrix1[i][j]);
        maxres += line1max[i];
      } else {
        for (int j = 0; j < N; j++)
          matrix[i + 1][j + 1] = -matrix2[i][j],
                            colmax[j] = max(colmax[j], matrix2[i][j]);
        maxres += line2max[i];
      }
    }
    for (int i = 0; i < N; i++) maxres2 += colmax[i];
    if (maxres > best && maxres2 > best) {
      res = -getresult(N);
      best = max(best, res);
    }
    return res;
  }
  int res = 0;
  if (rr[pos]) {
    if (cnt1 < N2) {
      mas[pos] = 1;
      res = max(res, go(pos + 1, N, N2, cnt1 + 1, cnt2));
    }
    if (cnt2 < N2) {
      mas[pos] = 2;
      res = max(res, go(pos + 1, N, N2, cnt1, cnt2 + 1));
    }
  } else {
    if (cnt2 < N2) {
      mas[pos] = 2;
      res = max(res, go(pos + 1, N, N2, cnt1, cnt2 + 1));
    }
    if (cnt1 < N2) {
      mas[pos] = 1;
      res = max(res, go(pos + 1, N, N2, cnt1 + 1, cnt2));
    }
  }
  itt++;
  if (itt & 63) {
    if (clock() * 1e-3 > 1.8) {
      stop = true;
      return res;
    }
  }
  return res;
}
int rowperm[22];
int colperm[22];
bool visrow[22];
bool viscol[22];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) rowperm[i] = i;
  for (int i = 0; i < N; i++) colperm[i] = i;
  srand(time(0));
  random_shuffle(rowperm, rowperm + N);
  random_shuffle(colperm, colperm + N);
  for (int i = 0; i < N; i++) rr[i] = rand() % 2;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) scanf("%d", &matrix1[rowperm[i]][colperm[j]]);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      line1max[i] = max(line1max[i], matrix1[i][j]);
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) scanf("%d", &matrix2[rowperm[i]][colperm[j]]);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      line2max[i] = max(line2max[i], matrix2[i][j]);
    }
  }
  int ost1 = N / 2;
  int ost2 = N / 2;
  memset(visrow, true, sizeof(visrow));
  memset(viscol, true, sizeof(viscol));
  for (int step = 0; step < N; step++) {
    int maxi1 = 0;
    int r1 = 0, c1 = 0;
    int maxi2 = 0;
    int r2 = 0, c2 = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (matrix1[i][j] > maxi1 && visrow[i] && viscol[j]) {
          maxi1 = matrix1[i][j];
          r1 = i;
          c1 = j;
        }
        if (matrix2[i][j] > maxi2 && visrow[i] && viscol[j]) {
          maxi2 = matrix2[i][j];
          r2 = i;
          c2 = j;
        }
      }
    }
    if (ost1 > 0 && maxi1 > maxi2) {
      ost1--;
      best += maxi1;
      visrow[r1] = false;
      viscol[c1] = false;
    } else if (ost2 > 0 && maxi2 > maxi1) {
      ost2--;
      best += maxi2;
      visrow[r2] = false;
      viscol[c2] = false;
    } else if (maxi1 == maxi2) {
      if (ost1 > ost2) {
        ost1--;
        best += maxi1;
        visrow[r1] = false;
        viscol[c1] = false;
      } else {
        ost2--;
        best += maxi2;
        visrow[r2] = false;
        viscol[c2] = false;
      }
    } else if (ost1 > 0) {
      ost1--;
      best += maxi1;
      visrow[r1] = false;
      viscol[c1] = false;
    } else {
      ost2--;
      best += maxi2;
      visrow[r2] = false;
      viscol[c2] = false;
    }
  }
  printf("%d\n", max(best, go(0, N, N / 2)));
  return 0;
}
