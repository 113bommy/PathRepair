#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 7;
int n;
int p[MX], Max[MX];
int c[MX], num[MX], k[MX];
int lowbit(int x) { return x & -x; }
int sum(int x) {
  int res = 0;
  while (x) {
    res += c[x];
    x -= lowbit(x);
  }
  return res;
}
void add(int x, int d) {
  while (x <= n) {
    c[x] += d;
    x += lowbit(x);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    num[i] = sum(n) - sum(p[i]);
    add(p[i], 1);
    Max[i] = max(Max[i - 1], p[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    if (num[i] == 1 && i > 2) {
      k[Max[i]]++;
    }
    if (num[i] == 0 && i != 1) {
      k[p[i]]--;
    }
  }
  int ans = 1, mm = -1;
  for (int i = 1; i <= n; i++) {
    if (i == p[1]) {
      if (p[1] < p[2]) continue;
    }
    if (k[i] > mm) {
      mm = k[i];
      ans = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
