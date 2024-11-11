#include <bits/stdc++.h>
using namespace std;
int d[205];
int ct[205], x[205];
int N, n;
vector<string> ans;
char str[30];
void gao(int a, int b) {
  sprintf(str, "%d %d", a, b);
  ans.push_back(str);
}
void sol(int dep, int a, int b, int s) {
  int c = 1;
  for (int i = 1; i <= 3; i++)
    if (i != a && i != b) c = i;
  if (dep == n - 1) {
    if (s)
      for (int i = 0; i < x[dep]; i++) gao(a, b);
    else {
      for (int i = 0; i < x[dep] - 1; i++) gao(a, c);
      gao(a, b);
      for (int i = 0; i < x[dep] - 1; i++) gao(c, b);
    }
    return;
  }
  if (s || x[dep] == 1) {
    sol(dep + 1, a, c, 0);
    for (int i = 0; i < x[dep]; i++) gao(a, b);
    sol(dep + 1, c, b, 0);
  } else {
    sol(dep + 1, a, b, 1);
    for (int i = 0; i < x[dep]; i++) gao(a, c);
    sol(dep + 1, b, a, 1);
    for (int i = 0; i < x[dep]; i++) gao(c, b);
    sol(dep + 1, a, b, 0);
  }
}
int main() {
  scanf("%d", &n);
  N = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) scanf("%d", &d[i]);
  for (int i = 0; i < n; i++) {
    cnt++;
    if (i == n - 1 || d[i] != d[i + 1]) {
      x[N++] = cnt;
      cnt = 0;
    }
  }
  if (N == 1) {
    printf("%d\n", n * 2 - 1);
    for (int i = 0; i < n - 1; i++) puts("1 2");
    puts("1 3");
    for (int i = 0; i < n - 1; i++) puts("2 3");
    return 0;
  }
  ans.clear();
  n = N;
  sol(0, 1, 3, 0);
  int ret = ans.size();
  printf("%d\n", ret);
  for (int i = 0; i < ret; i++) printf("%s\n", ans[i].c_str());
  return 0;
}
