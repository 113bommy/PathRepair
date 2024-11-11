#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k;
int l[N], r[N], x[N];
int main() {
  scanf("%d", &n), scanf("%d", &m), scanf("%d", &k);
  for (int i = 0; i < m; ++i)
    scanf("%d", &l[i]), scanf("%d", &r[i]), scanf("%d", &x[i]);
  long long out = 0;
  while (k--) {
    int idx;
    scanf("%d", &idx);
    for (int i = 0; i < m; i++) {
      if (idx < l[i] || idx > r[i]) continue;
      out += x[i] + idx - l[i];
    }
  }
  cout << out;
}
