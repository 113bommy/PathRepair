#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(INT_MAX / 2);
const int N = (int)(0);
const long long mod = (int)(1e+9 + 7);
int n, m, a, b, x, y, k, k1, k2, s, ans, pos, last, cnt, tam;
int main() {
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      if (j % 2 == 0)
        v[j] = (v[j] + 1) % n;
      else
        v[j] = (v[j] - 1 + n) % n;
    }
    for (pos = 0; pos < n; pos++)
      if (v[pos] != pos) break;
    if (pos == n) return puts("YES"), 0;
  }
  puts("NO");
  return 0;
}
