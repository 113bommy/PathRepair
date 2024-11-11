#include <bits/stdc++.h>
using namespace std;
int n;
char s[500005];
int x[500005], y[500005];
int a, b;
int l, r, u, d, big, small;
bool C(int m) {
  l = 0, r = INT_MAX, u = INT_MAX, d = 0, big = INT_MAX, small = -INT_MAX;
  for (int i = 1; i <= n; i++) {
    l = max(l, x[i] - m);
    r = min(r, x[i] + m);
    d = max(d, y[i] - m);
    u = min(u, y[i] + m);
    big = min(big, x[i] - y[i] + m);
    small = max(small, x[i] - y[i] - m);
  }
  if (l > r || d > u || small > big || l - u > big || r - d < small) return 0;
  return 1;
}
void decide() {
  a = l;
  for (b = d; b <= u; b++) {
    if (a - b >= small && a - b <= big) return;
  }
  b = d;
  for (a = l; a <= r; a++) {
    if (a - b >= small && a - b <= big) return;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    for (int j = 0; j < len; j++) {
      if (s[j] == 'B')
        y[i]++;
      else
        x[i]++;
    }
  }
  int lb = -1, ub = 500005;
  while (ub - lb > 1) {
    int mid = (ub + lb) >> 1;
    if (C(mid))
      ub = mid;
    else
      lb = mid;
  }
  printf("%d\n", ub);
  C(ub);
  decide();
  for (int i = 0; i < a; i++) printf("N");
  for (int i = 0; i < b; i++) printf("B");
  return 0;
}
