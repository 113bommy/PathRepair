#include <bits/stdc++.h>
using namespace std;
int a, i, j, n, aux, cnt, ans, div1[10000010], v[10000010];
int main() {
  cin >> a >> n;
  v[1] = 1;
  for (i = 3; i * i <= a + n - 1; i += 2)
    if (!div1[i]) {
      div1[i] = i;
      for (j = i * i; j <= a + n - 1; j += 2 * i) div1[j] = i;
    }
  for (i = 2; i <= a + n - 1; i += 2) div1[i] = 2;
  for (i = 2; i <= a + n - 1; i++) {
    aux = i;
    cnt = 0;
    if (!div1[i]) div1[i] = i;
    while (aux % div1[i] == 0) aux /= div1[i], cnt++;
    v[i] = v[aux];
    if (cnt & 1) v[i] *= div1[i];
  }
  for (i = a; i <= a + n - 1; i++) ans += v[i];
  cout << ans;
  return 0;
}
