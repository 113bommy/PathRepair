#include <bits/stdc++.h>
using namespace std;
int inp[110];
int main() {
  int n, i, s, t, sum = 0, allsum = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", inp + i);
    allsum += inp[i];
  }
  scanf("%d%d", &s, &t);
  if (s > t) {
    swap(s, t);
  }
  for (i = s; i < t; i++) {
    sum += inp[s];
  }
  printf("%d", min(sum, allsum - sum));
}
