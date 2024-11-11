#include <bits/stdc++.h>
using namespace std;
int secday = 86400;
int month[15] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int upto[15];
int vals[10000000];
char base[10000500];
int a, n, m;
int day, mon, hour, sec, mint;
int main() {
  for (a = 2; a <= 12; a++) upto[a] = upto[a - 1] + month[a - 1];
  scanf("%d%d", &n, &m);
  int last = 1;
  int now = 0;
  scanf("%d-%d-%d %d:%d:%d", &a, &mon, &day, &hour, &mint, &sec);
  now++;
  vals[now] = (upto[mon] + day) * secday + hour * 3600 + mint * 60 + sec;
  gets(base);
  while (scanf("%d-%d-%d %d:%d:%d", &a, &mon, &day, &hour, &mint, &sec) > 0) {
    now++;
    vals[now] = (upto[mon] + day) * secday + hour * 3600 + mint * 60 + sec;
    gets(base);
    while (vals[now] - vals[last] >= n) last++;
    if (now - last + 1 >= m) {
      printf("%d-", a);
      if (mon < 10) printf("0");
      printf("%d-", mon);
      if (day < 10) printf("0");
      printf("%d ", day);
      if (hour < 10) printf("0");
      printf("%d:", hour);
      if (mint < 10) printf("0");
      printf("%d:", mint);
      if (sec < 10) printf("0");
      printf("%d", sec);
      return 0;
    }
  }
  printf("-1");
}
