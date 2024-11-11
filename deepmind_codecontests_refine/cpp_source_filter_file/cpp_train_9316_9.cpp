#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int A[maxn], B[maxn], C[maxn], id[maxn];
int N, K;
pair<int, int> ans[maxn];
int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) scanf("%d%d%d", &A[i], &B[i], &C[i]);
  srand(970516);
  for (int T = 1; T <= 200; T++) {
    int flag = 1;
    for (int i = 1; i <= N; i++) id[i] = i;
    int tot = N;
    for (int now = 1; now <= K + 1; now++) {
      if (flag && tot == 0) {
        puts("YES");
        cout << now - 1 << endl;
        for (int i = 1; i < now; i++) {
          printf("%d %d\n", ans[i].first, ans[i].second);
        }
        return 0;
      }
      int a = id[rand() % tot + 1], b = id[rand() % tot + 1];
      if (a == b) {
        ans[now] = make_pair(a, -1);
        int cnt = 0;
        for (int i = 1; i < tot; i++)
          if (i != a) id[++cnt] = id[i];
        tot = cnt;
      } else {
        ans[now] = make_pair(a, b);
        long long t = 1LL * A[b] * B[a] - 1LL * A[a] * B[b];
        if (t == 0) {
          flag = 0;
          break;
        } else {
          long long x = -1LL * B[a] * C[b] + 1LL * B[b] * C[a];
          long long y = 1LL * A[a] * C[b] - 1LL * A[b] * C[a];
          int cnt = 0;
          for (int c = 1; c <= tot; c++)
            if (A[id[c]] * x + B[id[c]] * y + C[id[c]] * t != 0)
              id[++cnt] = id[c];
          tot = cnt;
        }
      }
    }
  }
  puts("NO");
  return 0;
}
