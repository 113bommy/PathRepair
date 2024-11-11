#include <bits/stdc++.h>
using namespace std;
int v[9999999];
int res[9999999];
int main() {
  int i, n, x;
  long long int counter = 0;
  scanf("%d%d", &n, &x);
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for (i = 0; i < n; i++) {
    res[v[i] ^ x]++;
  }
  for (i = 0; i < n; i++) {
    counter += res[v[i]];
    if (!x && res[v[i]]) counter--;
  }
  printf("%I64d\n", counter / 2);
  return 0;
}
