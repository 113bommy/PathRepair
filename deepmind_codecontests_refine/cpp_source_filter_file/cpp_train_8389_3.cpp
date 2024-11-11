#include <bits/stdc++.h>
using namespace std;
char op[4] = {'U', 'D', 'L', 'R'};
vector<char> ans;
vector<char> temp;
int visit[105][105];
int X[4] = {-1, 1, 0, 0};
int Y[4] = {0, 0, -1, 1};
char c[105][105];
int n, m;
void dfs(int first, int second) {
  if (c[first][second] == 'F') {
    ans = temp;
    return;
  }
  visit[first][second] = 1;
  for (int i = 0; i < 4; i++) {
    if (first + X[i] > 0 && first + X[i] <= n && second + Y[i] > 0 &&
        second + Y[i] <= m && c[first + X[i]][second + Y[i]] != '*' &&
        !visit[first + X[i]][second + Y[i]]) {
      temp.push_back(op[i]);
      dfs(first + X[i], second + Y[i]);
      temp.pop_back();
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
  int first = 1, second = 1;
  if (c[first][second] == 'F') return 0;
  int okud = 0, oklr = 0;
  if (c[first + 1][second] != '*') {
    printf("%c\n", op[0]);
    fflush(stdout);
    scanf("%d %d", &first, &second);
    if (c[first][second] == 'F') return 0;
    if (first != 1) {
      swap(op[0], op[1]);
      printf("%c\n", op[0]);
      fflush(stdout);
      scanf("%d %d", &first, &second);
      if (c[first][second] == 'F') return 0;
    }
    okud = 1;
  }
  if (c[first][second + 1] != '*') {
    printf("%c\n", op[2]);
    fflush(stdout);
    scanf("%d %d", &first, &second);
    if (c[first][second] == 'F') return 0;
    if (second != 1) {
      swap(op[2], op[3]);
      printf("%c\n", op[2]);
      fflush(stdout);
      scanf("%d %d", &first, &second);
      if (c[first][second] == 'F') return 0;
    }
    oklr = 1;
  }
  vector<char> v;
  if (!okud) {
    while (c[first + 1][second] == '*') {
      printf("%c\n", op[3]);
      v.push_back(op[2]);
      fflush(stdout);
      scanf("%d %d", &first, &second);
      if (c[first][second] == 'F') return 0;
    }
    printf("%c\n", op[0]);
    fflush(stdout);
    scanf("%d %d", &first, &second);
    if (c[first][second] == 'F') return 0;
    if (first != 1) {
      swap(op[0], op[1]);
      printf("%c\n", op[0]);
      fflush(stdout);
      scanf("%d %d", &first, &second);
    }
    while (!v.empty()) {
      printf("%c\n", v.back());
      v.pop_back();
      fflush(stdout);
      scanf("%d %d", &first, &second);
    }
  }
  if (!oklr) {
    while (c[first][second + 1] == '*') {
      printf("%c\n", op[1]);
      v.push_back(op[0]);
      fflush(stdout);
      scanf("%d %d", &first, &second);
      if (c[first][second] == 'F') return 0;
    }
    printf("%c\n", op[2]);
    fflush(stdout);
    scanf("%d %d", &first, &second);
    if (c[first][second] == 'F') return 0;
    if (second != 1) {
      swap(op[2], op[3]);
      printf("%c\n", op[0]);
      fflush(stdout);
      scanf("%d %d", &first, &second);
    }
    while (!v.empty()) {
      printf("%c\n", v.back());
      v.pop_back();
      fflush(stdout);
      scanf("%d %d", &first, &second);
    }
  }
  assert(first == 1 && second == 1);
  memset(visit, 0, sizeof(visit));
  dfs(first, second);
  for (vector<char>::iterator it = ans.begin(); it != ans.end(); it++) {
    printf("%c\n", *it);
    fflush(stdout);
    scanf("%d %d", &first, &second);
  }
  return 0;
}
