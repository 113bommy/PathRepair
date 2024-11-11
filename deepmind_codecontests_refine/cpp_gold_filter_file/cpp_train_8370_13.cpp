#include <bits/stdc++.h>
using namespace std;
const int Max = 2000100;
int n, m, number;
long long num[Max];
int w[Max];
int cmp(int x, int y) { return x > y; }
int main() {
  for (long long i = 1; i < Max; i++) {
    if (i % 2 == 1) {
      num[i] = i * (i - 1) / 2 + 1;
    } else {
      num[i] = i * i / 2;
    }
  }
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &number, &w[i]);
  }
  sort(w + 1, w + m + 1, cmp);
  int pos = upper_bound(num, num + Max, n) - num;
  pos--;
  long long ans = 0;
  for (int i = 1; i <= min(m, pos); i++) {
    ans += w[i];
  }
  printf("%I64d\n", ans);
  return 0;
}
