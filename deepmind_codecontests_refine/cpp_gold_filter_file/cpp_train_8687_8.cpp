#include <bits/stdc++.h>
using namespace std;
long long s[2009];
int main() {
  int n, m, k;
  int me[25];
  while ((scanf("%d%d%d", &n, &m, &k)) != EOF) {
    for (int i = 0; i <= m; i++) scanf("%I64dd", &s[i]);
    long long temp = s[m];
    for (int i = n - 1; i >= 0; i--) {
      me[i] = temp % 2;
      temp /= 2;
    }
    int have = 0;
    for (int i = 0; i < m; i++) {
      int diff = 0;
      for (int j = n - 1; j >= 0; j--) {
        if (s[i] % 2 != me[j]) diff++;
        s[i] /= 2;
      }
      if (diff <= k) have++;
    }
    cout << have << endl;
  }
  return 0;
}
