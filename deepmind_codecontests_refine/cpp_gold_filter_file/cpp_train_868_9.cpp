#include <bits/stdc++.h>
using namespace std;
const int dim[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char second[5555555];
struct rec {
  int y, m, d, hh, mm, ss;
  long long t;
} a[2222222];
int N, M, an;
int y, m, d, hh, mm, ss;
long long get() {
  long long sum = 0, res = 0;
  for (int i = 1; i < m; ++i) sum += dim[i];
  sum += d - 1;
  res = sum * 24 * 3600;
  res += hh * 3600;
  res += mm * 60 + ss;
  return res;
}
int main() {
  scanf("%d%d\n", &N, &M);
  while (scanf("%d-%d-%d %d:%d:%d", &y, &m, &d, &hh, &mm, &ss) == 6) {
    gets(second);
    a[an].y = y, a[an].m = m, a[an].d = d, a[an].hh = hh, a[an].mm = mm,
    a[an].ss = ss;
    a[an].t = get();
    ++an;
  }
  int i = 0;
  for (int j = 0; j < an; ++j) {
    while (i < j && a[j].t - a[i].t >= N) ++i;
    if (j - i + 1 >= M) {
      printf("%04d-%02d-%02d %02d:%02d:%02d\n", a[j].y, a[j].m, a[j].d, a[j].hh,
             a[j].mm, a[j].ss);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
