#include <bits/stdc++.h>
using namespace std;
char check[10][100] = {"0",     "9",      "99",      "099",      "3099",
                       "13099", "113099", "1113099", "11130999", "111130999"};
long long cmp[10] = {0,     1989,   1999,    2099,     3099,
                     13099, 113099, 1113099, 11130999, 111130999};
char in[100];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    scanf("%s", in);
    int l = strlen(in) - 4;
    long long v = atol(&in[4]);
    long long vv = atol(check[l]);
    if (strcmp(check[l], &in[4]) > 0) {
      long long p = 1;
      for (int j = 0; j < (l); ++j) p *= 10;
      printf("%lld\n", cmp[l] + p + v - vv);
    } else
      printf("%lld\n", cmp[l] + v - vv);
  }
  return 0;
}
