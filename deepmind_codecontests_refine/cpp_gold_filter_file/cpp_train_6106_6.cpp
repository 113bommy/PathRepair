#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 1e9;
int N, D;
int L = -inf, R = inf;
int a[maxn];
char b[maxn], o[maxn];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", a + i);
  }
  scanf("%s", b + 1);
  for (int i = 1; i <= 4; i++) o[i] = '0';
  int num[2];
  for (int i = 5; i <= N; i++) {
    num[0] = num[1] = 0;
    int n = a[i], u = a[i];
    for (int cnt = 1; cnt <= 4; cnt++) {
      num[b[i - cnt] - '0']++;
      n = max(n, a[i - cnt]);
      u = min(u, a[i - cnt]);
    }
    if (num[0] == 4) {
      if (b[i] == '1') {
        L = max(L, n + 1);
      } else {
        L = min(L, n);
      }
    } else if (num[1] == 4) {
      if (b[i] == '0') {
        R = min(R, u - 1);
      } else {
        R = max(R, u);
      }
    } else {
      assert(o[i - 1] == b[i]);
    }
    o[i] = b[i];
  }
  printf("%d %d\n", min(L, R), R);
}
