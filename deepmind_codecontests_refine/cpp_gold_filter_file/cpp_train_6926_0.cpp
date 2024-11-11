#include <bits/stdc++.h>
using namespace std;
int n, i, dim;
char s[111];
long long bg[15];
long long poww[15];
long long brute() {
  long long i;
  long long nr = 0;
  for (i = 0; i < dim; i++) nr += 1LL * poww[i] * (s[dim - i] - '0');
  for (i = bg[dim]; i < bg[dim + 1]; i++)
    if (nr == (i % poww[dim])) return i;
}
long long smart() {
  int i;
  long long nr = 0;
  for (i = 0; i < dim; i++) nr += 1LL * poww[i] * (s[dim - i] - '0');
  if (nr < bg[dim])
    return poww[dim] + nr;
  else
    return nr;
}
long long get_year() {
  int i;
  dim = strlen(s + 1);
  dim -= 4;
  for (i = 1; i <= dim; i++) s[i] = s[i + 4];
  if (dim <= 3)
    return brute();
  else
    return smart();
}
int main() {
  bg[1] = 1989;
  poww[0] = 1;
  poww[1] = 10;
  for (i = 2; i <= 14; i++)
    bg[i] = bg[i - 1] + 1LL * poww[i - 1], poww[i] = poww[i - 1] * 10LL;
  scanf("%d\n", &n);
  for (i = 1; i <= n; i++) {
    memset(s, 0, sizeof(s));
    scanf("%s\n", s + 1);
    printf("%lld\n", get_year());
  }
  return 0;
}
