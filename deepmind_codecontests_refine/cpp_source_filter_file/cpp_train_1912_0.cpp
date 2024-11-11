#include <bits/stdc++.h>
using namespace std;
int n, m;
char t[100][10000];
int ret[10000];
int findLeft(char *row, int pos) {
  for (int i = pos; i >= 0; --i)
    if (row[i] == '1') return i;
  for (int i = m - 1; i > pos; --i)
    if (row[i] == '1') return i;
  return -1;
}
int findRight(char *row, int pos) {
  for (int i = pos + 1; i < m; ++i)
    if (row[i] == '1') return i;
  for (int i = 0; i <= pos; ++i)
    if (row[i] == '1') return i;
  return -1;
}
void solveRow(int row, char *t) {
  int left = findLeft(t, 0);
  int right = findRight(t, 0);
  if (left == -1) {
    printf("-1");
    exit(0);
  }
  for (int i = 0; i < m; ++i) {
    if (right == i) {
      left = right;
      right = findRight(t, i);
    }
    int rightRet = (right - i + m) % m;
    int leftRet = (i - left + m) % m;
    ret[i] += rightRet < leftRet ? rightRet : leftRet;
  }
}
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", t[i]);
  }
  for (int i = 0; i < n; ++i) solveRow(i, t[i]);
  int rett = n * m;
  for (int j = 0; j < m; ++j) {
    rett = rett > ret[j] ? ret[j] : rett;
  }
  printf("%d\n", rett);
  return 0;
}
