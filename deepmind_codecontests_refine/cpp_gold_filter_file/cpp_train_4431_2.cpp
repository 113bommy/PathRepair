#include <bits/stdc++.h>
using namespace std;
long long v[100002];
bool id[100002] = {0};
int main() {
  long long s = 0, sv = 0, stemp = 0;
  long long temp;
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &v[i]);
    sv += v[i];
  }
  for (int i = 1; i <= k; i++) {
    scanf("%lld", &temp);
    id[temp] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (id[i]) {
      s = s + (sv - stemp - v[i]) * v[i];
      stemp += v[i];
    } else if (id[i % n + 1] == 0)
      s = s + v[i] * v[i % n + 1];
  }
  printf("%lld", s);
  return 0;
}
