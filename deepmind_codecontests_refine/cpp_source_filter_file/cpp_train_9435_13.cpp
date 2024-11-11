#include <bits/stdc++.h>
using namespace std;
int N, M;
void f(vector<int> &a, vector<int> &ret) {
  ret.clear();
  for (int i = 0; i < a.size(); i += 2) {
    ret.push_back(a[i]);
  }
  for (int i = 1; i < a.size(); i += 2) {
    ret.push_back(a[i]);
  }
}
void Shift(vector<int> &a, int x, vector<int> &ret) {
  ret = vector<int>(a.size());
  for (int i = 0; i < a.size(); i++) {
    ret[(i + x) % a.size()] = a[i];
  }
}
vector<vector<int> > ans;
vector<int> chk;
void dfs(int x) {
  if (x == N * M) {
    printf("YES\n");
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        printf("%d ", ans[i][j] + 1);
      }
      printf("\n");
    }
    exit(0);
  }
  int r = x / M;
  int c = x % M;
  for (int i = 0; i < N * M; i++) {
    if (!chk[i] &&
        (r == 0 ||
         abs(ans[r - 1][c] - i) != M && abs(ans[r - 1][c] - i) != 1) &&
        (c == 0 ||
         abs(ans[r][c - 1] - i) != 1 && abs(ans[r][c - 1] - i != M))) {
      ans[r][c] = i;
      chk[i] = 1;
      dfs(x + 1);
      chk[i] = 0;
    }
  }
}
int main() {
  scanf("%d %d", &N, &M);
  if (N <= 4 && M <= 4) {
    ans = vector<vector<int> >(N, vector<int>(M));
    chk = vector<int>(N * M, 0);
    dfs(0);
    printf("NO");
    return 0;
  }
  ans = vector<vector<int> >(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      ans[i][j] = i * M + j;
    }
  }
  if (N > M) {
    for (int i = 0; i < M; i++) {
      vector<int> tmp, res;
      for (int j = 0; j < N; j++) tmp.push_back(ans[j][i]);
      f(tmp, res);
      for (int j = 0; j < N; j++) ans[j][i] = res[j];
    }
    for (int i = 0; i < M; i += 2) {
      vector<int> tmp, res;
      for (int j = 0; j < N; j++) tmp.push_back(ans[j][i]);
      Shift(tmp, 1, res);
      for (int j = 0; j < N; j++) ans[j][i] = res[j];
    }
  } else {
    for (int i = 0; i < N; i++) {
      vector<int> tmp, res;
      for (int j = 0; j < M; j++) tmp.push_back(ans[i][j]);
      f(tmp, res);
      for (int j = 0; j < M; j++) ans[i][j] = res[j];
    }
    for (int i = 0; i < N; i += 2) {
      vector<int> tmp, res;
      for (int j = 0; j < M; j++) tmp.push_back(ans[i][j]);
      Shift(tmp, 1, res);
      for (int j = 0; j < M; j++) ans[i][j] = res[j];
    }
  }
  printf("YES\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", ans[i][j] + 1);
    }
    printf("\n");
  }
}
