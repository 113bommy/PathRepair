#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, q;
int cnt[N], last[N];
int main() {
  ios_base::sync_with_stdio(0);
  while (scanf("%d%d", &n, &q) == 2) {
    int sum = 0;
    memset(cnt, 0, sizeof cnt);
    memset(last, 0, sizeof last);
    vector<pair<int, int> > v(q + 1);
    int ptr = 1, last3 = 0;
    for (int i = 1; i <= q; ++i) {
      int op, x;
      scanf("%d%d", &op, &x);
      v[i] = {op, x};
      if (op == 1) {
        sum += 1;
        cnt[x] += 1;
      } else if (op == 2) {
        last[x] = i;
        sum -= cnt[x];
        cnt[x] = 0;
      } else {
        while (last3 < x) {
          int t, y;
          tie(t, y) = v[ptr++];
          if (t == 1) {
            if (last[y] < i) {
              --cnt[y];
              --sum;
            }
            ++last3;
          }
        }
      }
      printf("%d\n", sum);
    }
  }
  return 0;
}
