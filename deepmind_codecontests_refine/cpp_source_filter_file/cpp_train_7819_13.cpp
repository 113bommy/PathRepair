#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v[200003], m[200003], Max = 0;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    m[i] = 0;
    scanf("%d", &v[i]);
    for (int j = 0; j < v[i]; j++) {
      int aux;
      scanf("%d", &aux);
      m[i] = max(m[i], aux);
    }
    Max = max(Max, m[i]);
  }
  for (int i = 0; i < n; i++) {
    ans += (Max - m[i]) * v[i];
  }
  printf("%I64d", ans);
  return 0;
}
