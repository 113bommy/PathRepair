#include <bits/stdc++.h>
using namespace std;
const int NMax = 1700;
const long long INF = 1000000007LL;
int N, M, ID[NMax][NMax], ID1[NMax][NMax];
int A[NMax][NMax];
int F[NMax][NMax];
pair<int, int> Max[100], Min[100], Max1[100], Min1[100];
bool check(int first, int second) {
  return first > 0 && first <= N && second > 0 && second <= M &&
         A[first][second] && !ID[first][second];
}
void DFS(int a, int b, int c) {
  ID[a][b] = c;
  Max[c].first = max(Max[c].first, a);
  Max[c].second = max(Max[c].second, b);
  Min[c].first = min(Min[c].first, a);
  Min[c].second = min(Min[c].second, b);
  if (check(a - 1, b)) DFS(a - 1, b, c);
  if (check(a + 1, b)) DFS(a + 1, b, c);
  if (check(a, b - 1)) DFS(a, b - 1, c);
  if (check(a, b + 1)) DFS(a, b + 1, c);
}
bool check1(int first, int second, int z) {
  return first > 0 && first <= N && second > 0 && second <= M &&
         ID1[first][second] == z && !F[first][second];
}
int size[100];
void DFS(int a, int b, int c, int d) {
  F[a][b] = c;
  size[c]++;
  if (check1(a - 1, b, d)) DFS(a - 1, b, c, d);
  if (check1(a + 1, b, d)) DFS(a + 1, b, c, d);
  if (check1(a, b - 1, d)) DFS(a, b - 1, c, d);
  if (check1(a, b + 1, d)) DFS(a, b + 1, c, d);
}
bool check(int a, int b, int c) {
  return a > 0 && a <= N && b > 0 && b <= M && ID[a][b] == c;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
  int nn = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (A[i][j] && !ID[i][j]) {
        Max[++nn] = make_pair(-1, -1);
        Min[nn] = make_pair(2000, 2000);
        DFS(i, j, nn);
      }
  for (int i = 1; i <= nn; i++) {
    Max1[i] = make_pair(-1, -1);
    Min1[i] = make_pair(2000, 2000);
    for (int j = Min[i].first; j <= Max[i].first; j++) {
      for (int k = Min[i].second; k <= Max[i].second; k++)
        if (ID[j][k] == i) {
          int t1 = j, t2 = k;
          while (check(t1 - 1, k, i)) t1--;
          int start = t1;
          t1 = j;
          while (check(t1 + 1, k, i)) t1++;
          int last = t1;
          int X = last - start + 1;
          while (check(j, t2 - 1, i)) t2--;
          start = t2;
          t2 = k;
          while (check(j, t2 + 1, i)) t2++;
          last = t2;
          int Y = last - start + 1;
          if ((X < 15 || Y < 15)) {
            ID1[j][k] = i;
            Max1[i].first = max(Max1[i].first, j);
            Min1[i].first = min(Min1[i].first, j);
            Max1[i].second = max(Max1[i].second, k);
            Min1[i].second = min(Min1[i].second, k);
          }
        }
    }
  }
  printf("%d\n", nn);
  int Q[100], long long = 0;
  for (int i = 1; i <= nn; i++) {
    int cc = 0;
    for (int j = Min1[i].first; j <= Max1[i].first; j++)
      for (int k = Min1[i].second; k <= Max1[i].second; k++)
        if (!F[j][k] && ID1[j][k] == i) {
          size[++cc] = 0;
          DFS(j, k, cc, i);
        }
    int ret = cc;
    for (int c = 1; c <= cc; c++) {
      if (size[c] < 20) {
        ret--;
        continue;
      }
      int have = 0, flag = 0, cnt1 = 0;
      for (int j = Min1[i].first; j <= Max1[i].first && !flag; j++) {
        have = 0;
        for (int k = Min1[i].second; k <= Max1[i].second; k++)
          if (F[j][k] == c && ID1[j][k] == i)
            if (F[j][k - 1] != c) have++;
        if (have > 1) cnt1++;
      }
      int cnt = 0;
      for (int j = Min1[i].second; j <= Max1[i].second && !flag; j++) {
        have = 0;
        for (int k = Min1[i].first; k <= Max1[i].first; k++)
          if (F[k][j] == c && ID1[k][j] == i) {
            if (F[k - 1][j] != c) have++;
          }
        if (have > 1) cnt++;
      }
      if (cnt >= 10 || cnt1 >= 10) ret++;
    }
    Q[long long ++] = ret;
  }
  sort(Q, Q + long long);
  for (int i = 0; i < long long; i++) printf("%d ", Q[i]);
  puts("");
  return 0;
}
