#include <bits/stdc++.h>
using namespace std;
char s[100000];
int k;
int v[50], n;
long long sum;
int maxim;
int main() {
  int i, j;
  scanf("%s", &s);
  scanf("%d", &k);
  for (i = 0; i <= 25; i++) {
    scanf("%d", &v[i]);
    maxim = max(maxim, v[i]);
  }
  n = strlen(s);
  for (i = 0; i < n; i++) {
    sum += 1LL * v[s[i] - 'a'] * (i + 1);
  }
  i = n + 1;
  while (k != 0) {
    sum += 1LL * i * maxim;
    i++;
    k--;
  }
  printf("%I64d\n", sum);
  return 0;
}
