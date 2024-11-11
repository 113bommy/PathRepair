#include <bits/stdc++.h>
using namespace std;
int n, want;
int ret[100000];
void run() {
  scanf("%d%d", &n, &want);
  int npair = n / 2;
  if (want < npair || npair == 0 && want != 0) {
    printf("-1\n");
    return;
  }
  if (npair == 0) {
    printf("1\n");
    return;
  }
  int first = want - (npair - 1);
  ret[0] = first;
  ret[1] = 2 * first;
  int at = 1;
  for (int i = (1); i < (npair); ++i) {
    while (at == ret[0] || at == ret[1] || at + 1 == ret[0] || at + 1 == ret[1])
      ++at;
    ret[2 * i] = at;
    ret[2 * i + 1] = at + 1;
    at += 2;
  }
  for (int i = (2 * npair); i < (n); ++i) {
    while (at == ret[0] || at == ret[1]) ++at;
    ret[i] = at;
    ++at;
  }
  for (int i = (0); i < (n); ++i) {
    if (i != 0) printf(" ");
    printf("%d", ret[i]);
  }
  puts("");
}
int main() {
  run();
  return 0;
}
