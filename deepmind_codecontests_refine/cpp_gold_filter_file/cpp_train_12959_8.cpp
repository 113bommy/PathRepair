#include <bits/stdc++.h>
using namespace std;
int n, m, pointl[5], pointr[5];
int a[200005], num[200005], cont[200005];
long long ans = 0;
void force(int start, int end, int c) {
  int i = start;
  cont[i]++;
  while (1) {
    if (i == end && cont[i] == num[i]) return;
    if (i == 1 || i == n) {
      if (i + c > n || i + c < 1) c *= -1;
    }
    i += c;
    long long ret;
    ret = a[i] - a[i - c];
    if (ret < 0) ret *= -1;
    ans += ret;
    cont[i]++;
  }
}
void simple() {
  int start, end;
  if (num[1] > num[2])
    start = 1, end = 1;
  else if (num[1] < num[2])
    start = 2, end = 2;
  else if (num[1] == num[2])
    start = 1, end = 2;
  force(start, end, 1);
  printf("%I64d", ans);
}
void doleft() {
  if (num[1] == 0) {
    int i = 1;
    while (num[i] == 0) i++;
    pointr[0]++;
    pointr[pointr[0]] = i;
    return;
  }
  if (num[1] * 2 > num[2]) {
    pointl[0]++;
    pointl[pointl[0]] = 1;
    if (num[1] * 2 - 1 > num[2]) {
      pointl[0]++;
      pointl[pointl[0]] = 1;
    }
  }
  bool flag = 0;
  int i = 2;
  while (i <= n) {
    if (flag == 1 && num[i] > num[i - 1]) break;
    if (num[i] < num[i - 1] && i != n) {
      flag = 1;
      pointl[0]++;
      pointl[pointl[0]] = i - 1;
      if (num[i] < num[i - 1] - 1) {
        flag = 1;
        pointl[0]++;
        pointl[pointl[0]] = i - 1;
      }
    }
    if (i == n && 2 * num[n] < num[i - 1]) {
      flag = 1;
      pointl[0]++;
      pointl[pointl[0]] = i - 1;
      if (2 * num[n] + 1 < num[i - 1]) {
        flag = 1;
        pointl[0]++;
        pointl[pointl[0]] = i - 1;
      }
    }
    i++;
  }
}
void doright() {
  if (num[n] == 0) {
    int i = n;
    while (num[i] == 0) i--;
    pointl[0]++;
    pointl[pointl[0]] = i;
    return;
  }
  if (num[n] * 2 > num[n - 1]) {
    pointr[0]++;
    pointr[pointr[0]] = n;
    if (num[n] * 2 - 1 > num[n - 1]) {
      pointr[0]++;
      pointr[pointr[0]] = n;
    }
  }
  bool flag = 0;
  int i = n - 1;
  while (i >= 1) {
    if (flag == 1 && num[i] > num[i + 1]) break;
    if (num[i] < num[i + 1] && i != 1) {
      flag = 1;
      pointr[0]++;
      pointr[pointr[0]] = i + 1;
      if (num[i] < num[i + 1] - 1) {
        flag = 1;
        pointr[0]++;
        pointr[pointr[0]] = i + 1;
      }
    }
    if (i == 1 && 2 * num[1] < num[i + 1]) {
      flag = 1;
      pointr[0]++;
      pointr[pointr[0]] = i + 1;
      if (2 * num[1] + 1 < num[i + 1]) {
        flag = 1;
        pointr[0]++;
        pointr[pointr[0]] = i + 1;
      }
    }
    i--;
  }
}
bool check() {
  for (int i = 3; i <= n; i++)
    if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int ret;
    scanf("%d", &ret);
    num[ret]++;
  }
  if (n == 2)
    simple();
  else {
    doleft();
    doright();
    if (pointl[0] == 0 && pointr[0] == 0) {
      if (check()) {
        force(1, 2, 1);
        printf("%I64d\n", ans);
      } else
        printf("-1");
    } else if (pointl[0] == 0) {
      force(pointr[1], pointr[2], 1);
      printf("%I64d\n", ans);
    } else if (pointr[0] == 0) {
      force(pointl[1], pointl[2], -1);
      printf("%I64d\n", ans);
    } else {
      force(pointl[1], pointr[1], -1);
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
