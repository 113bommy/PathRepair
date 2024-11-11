#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101010;
const int INF = 1000010001;
int n, k, l, a[MAXN], b[MAXN];
bool fix[MAXN], visited[MAXN];
int getInt(char str[]) {
  int len = strlen(str), num = 0, j = 0;
  if (str[0] == '-') j = 1;
  for (int i = j; i < len; i++) num = num * 10 + str[i] - '0';
  if (j == 1) num = -num;
  return num;
}
void read() {
  scanf("%d%d", &n, &k);
  memset(fix, false, sizeof(fix));
  char str[12];
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    if (str[0] != '?') {
      a[i] = getInt(str);
      fix[i] = true;
    }
  }
}
bool getOptimal(int lower, int upper) {
  if (upper - lower < l) return false;
  if (lower >= 0) {
    a[b[0]] = lower + 1;
    for (int i = 1; i < l; i++) a[b[i]] = a[b[i - 1]] + 1;
  } else if (upper <= 0) {
    a[b[l - 1]] = upper - 1;
    for (int i = l - 2; i >= 0; i--) a[b[i]] = a[b[i + 1]] - 1;
  } else {
    int len = l / 2;
    if (-lower > len && upper > len) {
      a[b[len]] = 0;
      for (int i = len - 1; i >= 0; i--) a[b[i]] = a[b[i + 1]] - 1;
      for (int i = len + 1; i < l; i++) a[b[i]] = a[b[i - 1]] + 1;
    } else if (-lower > len) {
      a[b[l - 1]] = upper - 1;
      for (int i = l - 2; i >= 0; i--) a[b[i]] = a[b[i + 1]] - 1;
    } else {
      a[b[0]] = lower + 1;
      for (int i = 1; i < l; i++) a[b[i]] = a[b[i - 1]] + 1;
    }
  }
  return true;
}
bool solve() {
  int lower = -INF, upper = INF;
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < n; i++)
    if (!visited[i]) {
      lower = -INF;
      upper = INF;
      l = 0;
      for (int j = i; j < n; j += k) {
        visited[j] = true;
        if (fix[j]) {
          if (a[j] <= lower) return false;
          if (l == 0) {
            lower = a[j];
          } else {
            upper = a[j];
            if (!getOptimal(lower, upper)) return false;
            l = 0;
            lower = a[j];
            upper = INF;
          }
        } else {
          b[l++] = j;
        }
      }
      if (l > 0)
        if (!getOptimal(lower, upper)) return false;
    }
  return true;
}
int main() {
  read();
  if (!solve())
    puts("Incorrect sequence");
  else {
    for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
  }
  return 0;
}
