#include <bits/stdc++.h>
using namespace std;
int T, N;
int ary[300000] = {0};
int bry[300000] = {0};
void prepare() {
  cin >> N;
  long long x, y;
  for (int i = 1; i <= N; i++) scanf("%d", &ary[i]);
  int a, b;
  if (N & 1) {
    for (int i = 1; i <= N - 2; i += 2) {
      bry[i] = ary[i + 1];
      bry[i + 1] = -ary[i];
    }
    a = ary[N];
    b = -ary[N - 1];
    if (a * bry[N - 1] > 0) {
      bry[N - 1] += a;
      bry[N] = b;
    } else {
      bry[N - 1] -= a;
      bry[N] = -b;
    }
  } else {
    for (int i = 1; i <= N - 1; i += 2) {
      bry[i] = ary[i + 1];
      bry[i + 1] = -ary[i];
    }
  }
  for (int i = 1; i <= N; i++) printf("%d ", bry[i]);
  printf("\n");
}
void solve() {}
int main() {
  cin >> T;
  while (T--) {
    prepare();
    solve();
  }
  return 0;
}
