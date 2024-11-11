#include <bits/stdc++.h>
using namespace std;
struct war {
  long long c, x;
};
const long long inf = 100000000000000000;
long long f[3500];
int n;
war w[3009];
bool comp(const war v1, const war v2) { return v1.x < v2.x; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &w[i].x, &w[i].c);
  }
  sort(w + 1, w + n + 1, comp);
  long long tmp;
  for (int i = n; i > 0; i--) {
    f[i] = inf;
    tmp = w[i].c;
    for (int j = i + 1; j <= n; j++) {
      f[i] = min(f[i], f[j] + tmp);
      tmp += w[j].x - w[i].x;
    }
    f[i] = min(f[i], tmp);
  }
  printf("%d\n", f[1]);
  return 0;
}
