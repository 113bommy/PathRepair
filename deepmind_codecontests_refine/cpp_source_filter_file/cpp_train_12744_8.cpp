#include <bits/stdc++.h>
using namespace std;
void time_start(clock_t *tt) { *tt = clock(); }
void print_time(clock_t tt) {
  tt = clock() - tt;
  printf("executed in %.f ms\n", (float)tt / CLOCKS_PER_SEC * 1000);
}
template <typename T>
inline T getnum() {
  T num = 0;
  char c;
  do {
    c = getchar();
  } while (c != EOF && c == ' ' && c == '\n' && c == '\t');
  int sign = (c == '-' ? -1 : 1);
  if (c != '-') num += (c - '0');
  while ((c = getchar()) != EOF && c != '\n' && c != '\t' && c != ' ') {
    num *= 10;
    num += (c - '0');
  }
  num *= sign;
  return num;
}
inline string getstr() {
  string str;
  char k;
  while ((k = getchar()) == ' ' || k == '\n') {
    k = getchar();
    if (k == ' ' || k == '\n')
      continue;
    else
      break;
  }
  while ((k = getchar()) != EOF && k != '\n' && k != '\t' && k != '\v' &&
         k != '\0' && k != ' ')
    str.push_back(k);
  return str;
}
int mat[5005][5005], res[5005][5005];
int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  memset(mat, 0, sizeof(mat));
  char t;
  for (int i = (int)0, _b = (int)n - 1; i <= _b; i++) {
    if (i) getchar();
    for (int j = (int)0, _b = (int)m - 1; j <= _b; j++) {
      t = getchar();
      mat[i][j] = t - '0';
    }
  }
  memset(res, 0, sizeof(res));
  for (int i = (int)0, _b = (int)n - 1; i <= _b; i++)
    for (int j = (int)m - 2, _b = (int)0; j >= _b; j--) {
      mat[i][j] = (mat[i][j] ? mat[i][j + 1] + 1 : 0);
      res[j][mat[i][j]]++;
    }
  long long ans = 0, cnt;
  for (int i = (int)0, _b = (int)m - 1; i <= _b; i++) {
    cnt = 0;
    for (int j = (int)m, _b = (int)0; j >= _b; j--) {
      cnt += res[i][j];
      ans = max(ans, cnt * j);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
