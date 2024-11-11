#include <bits/stdc++.h>
using namespace std;
int p[55];
int N, M;
long long f() {
  long long ans = 0;
  for (int i = 0; i < (N); i++)
    for (int j = 0; j < (i + 1); j++) {
      int m = p[j];
      for (int k = (j); k <= (i); k++) m = min(m, p[k]);
      ans += m;
    }
  return ans;
}
int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  long long max_f = -1;
  for (int i = 0; i < (N); i++) p[i] = i;
  do {
    max_f = max(max_f, f());
  } while (next_permutation(p, p + N));
  for (int i = 0; i < (N); i++) p[i] = i;
  do {
    if (f() && !(--M)) {
      for (int i = 0; i < (N); i++) {
        if (i) printf(" ");
        printf("%d", p[i] + 1);
      }
      printf("\n");
      break;
    }
  } while (next_permutation(p, p + N));
  return 0;
}
