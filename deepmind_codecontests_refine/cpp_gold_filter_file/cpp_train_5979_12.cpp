#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50007;
pair<int, int> X[2][MAXN], Y[2][MAXN];
int N, M;
void input() {
  scanf("%d %d", &N, &M);
  for (__typeof(N) i = 0; i < N; i++) {
    int x, y, l;
    scanf("%d %d %d", &Y[0][i].first, &Y[0][i].second, &l);
    Y[1][i] = Y[0][i];
    Y[1][i].second += l;
  }
  for (__typeof(M) i = 0; i < M; i++) {
    int x, y, l;
    scanf("%d %d %d", &X[0][i].first, &X[0][i].second, &l);
    X[1][i] = X[0][i];
    X[1][i].first += l;
  }
}
void solve() {
  int res = 0;
  for (__typeof(N) i = 0; i < N; i++)
    for (__typeof(M) j = 0; j < M; j++) {
      int tmp = INT_MAX;
      if (Y[0][i].second <= X[0][j].second && X[0][j].second <= Y[1][i].second)
        if (X[0][j].first <= Y[0][i].first && Y[0][i].first <= X[1][j].first) {
          tmp = min(tmp, X[0][j].second - Y[0][i].second);
          tmp = min(tmp, Y[1][i].second - X[0][j].second);
          tmp = min(tmp, Y[0][i].first - X[0][j].first);
          tmp = min(tmp, X[1][j].first - Y[0][i].first);
        }
      if (tmp < INT_MAX) res = max(res, tmp);
    }
  printf("%d\n", res);
}
int main() {
  input();
  solve();
}
