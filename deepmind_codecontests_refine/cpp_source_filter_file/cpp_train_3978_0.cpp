#include <bits/stdc++.h>
using namespace std;
const int N = 30000;
const int unknown = (int)1e9 + 28;
bool marked[2][N];
int a[N], n, finish[2];
void output() {
  for (int j = 0; j < 2; ++j) {
    for (int i = 0; i < n; ++i)
      if (marked[j][i] && (i < finish[j])) printf("%d ", a[i]);
    printf("\n");
  }
  exit(0);
}
void mark(int begin, int delta, bool* marked) {
  int current = begin;
  for (int i = 0; i < n; ++i)
    if (a[i] == current) marked[i] = true, current += delta;
}
void build(int begin1, int delta1, int begin2, int delta2) {
  memset(marked, 0, sizeof(marked));
  mark(begin1, delta1, marked[0]);
  mark(begin2, delta2, marked[1]);
  finish[0] = n, finish[1] = n;
  for (int i = 0; i < n - 1; ++i)
    if (marked[0][i] && marked[1][i])
      if (a[i + 1] - a[i] == delta1)
        finish[1] = min(finish[1], i);
      else
        finish[0] = min(finish[0], i);
  int current1 = begin1, current2 = begin2;
  for (int i = 0; i < n; ++i)
    if (marked[0][i] && (i < finish[0]))
      if (a[i] != current1)
        return;
      else
        current1 += delta1;
    else if (!marked[1][i] || (i >= finish[1]))
      return;
    else
      current2 += delta2;
  output();
}
void run(int begin, int delta) {
  int current = begin, otherbegin = unknown, otherdelta = unknown;
  for (int i = 0; i < n; ++i)
    if (a[i] == current)
      current += delta;
    else if (otherbegin == unknown)
      otherbegin = a[i];
    else if (otherdelta == unknown)
      otherdelta = a[i] - otherbegin;
  if (otherbegin == unknown) {
    finish[0] = finish[1] = n;
    memset(marked, 0, sizeof(marked));
    marked[0][0] = true;
    for (int i = 1; i < n; ++i) marked[1][i] = true;
    output();
  }
  int sign = otherdelta < 0 ? -1 : 1;
  for (int j = 1; j * j <= otherdelta * sign; ++j)
    if (otherdelta % j == 0) {
      build(begin, delta, otherbegin, j * sign);
      build(begin, delta, otherbegin, otherdelta / j);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  run(a[0], a[1] - a[0]);
  run(a[0], a[2] - a[0]);
  run(a[1], a[2] - a[1]);
  printf("No\n");
  return 0;
}
