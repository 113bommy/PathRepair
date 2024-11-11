#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 200010;
const int INF = 2147364800;
int N, tax[11], L[11], G[11][11], Nw[11], pw[11], all;
bool F[11];
vector<pair<int, int> > vec;
inline bool Hall() {
  for (int S = 1; S < (1 << all); S++) {
    int cntL = 0, cntR = 0;
    for (int i = 1; i <= all; i++)
      if (S & (1 << i - 1)) cntL += tax[i];
    for (int i = 1; i <= all; i++)
      for (int j = i; j <= all; j++)
        if ((S & (1 << i - 1)) || (S & (1 << j - 1))) cntR += G[i][j];
    if (cntR >= cntL) return 0;
  }
  return 1;
}
inline int get(int x) {
  int cnt = 0;
  while (x) ++cnt, x /= 10;
  return cnt;
}
int main() {
  N = read();
  for (int i = 1; i < N; i++) {
    char str[11];
    int x, y;
    scanf("%s", str);
    x = strlen(str);
    scanf("%s", str);
    y = strlen(str);
    ++G[x][y];
    if (x != y) ++G[y][x];
  }
  for (int i = 0; i <= 10; i++) L[i] = INF;
  for (int i = 1; i <= N; i++) {
    int tmp = get(i);
    ++tax[tmp];
    all = max(all, tmp), L[tmp] = min(L[tmp], i);
  }
  for (int i = 1; i <= all; i++) Nw[i] = L[i];
  pw[1] = 1;
  for (int i = 2; i <= all; i++) pw[i] = pw[i - 1] * 10;
  --tax[1], F[1] = 1, ++Nw[1];
  int LK = 0;
  while (LK < N - 1) {
    bool flag = 0;
    for (int i = 1; i <= all; i++)
      if (F[i]) {
        for (int j = 1; j <= all; j++) {
          if (!G[i][j] || !tax[j]) continue;
          --tax[j], --G[i][j];
          if (i != j) --G[j][i];
          if (Hall()) {
            ++LK, F[j] = 1, flag = 1;
            vec.push_back(make_pair(pw[i], Nw[j]++));
          } else {
            ++tax[j], ++G[i][j];
            if (i != j) ++G[j][i];
          }
        }
      }
    if (!flag) {
      printf("-1\n");
      return 0;
    }
  }
  for (auto gg : vec) printf("%d %d\n", gg.first, gg.second);
  return 0;
}
