#include <bits/stdc++.h>
using namespace std;
const int maxn = 111111;
pair<int, int> p[maxn];
int main() {
  int n, m, i, a, b;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    p[i] = pair<int, int>(a, b);
  }
  if (!m) {
    if (n & 1)
      puts("WIN");
    else
      puts("LOSE");
    return 0;
  }
  sort(p, p + m);
  int SG = (p[0].first - 1) ^ (n - p[m - 1].first);
  for (i = 1; i < m; ++i) {
    if (p[i - 1].second == p[i].second) {
      SG ^= (p[i].first + p[i - 1].first + 1) & 1;
    } else {
      SG ^= (p[i].first + p[i - 1].first) & 1;
    }
  }
  if (SG)
    puts("WIN");
  else
    puts("LOSE");
  return 0;
}
