#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, p[N];
namespace Subtask1 {
void dfs(int x) {
  if (!x) return;
  int k = 0;
  for (; (1 << k) < x; ++k)
    ;
  if ((1 << k) > x) --k;
  for (int i = (1 << k); i <= x; ++i)
    p[i] = (1 << k + 1) - i - 1, p[(1 << k + 1) - i - 1] = i;
  dfs((1 << k + 1) - x - 2);
}
void main() {
  if (n & 1) {
    puts("NO");
    return;
  }
  dfs(n);
  puts("YES");
  for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
  puts("");
}
}  // namespace Subtask1
namespace Subtask2 {
void main() {
  for (int i = 1; i <= n; ++i) p[i] = i;
  if (n <= 7) {
    bool ok = 0;
    do {
      bool fl = 1;
      for (int i = 1; i <= n; ++i)
        if (!(p[i] & i) || i == p[i]) {
          fl = 0;
          break;
        }
      if (fl) {
        ok = 1;
        break;
      }
    } while (next_permutation(p + 1, p + n + 1));
    if (!ok) {
      puts("NO");
      return;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
    return;
  }
  if (n & 1) {
    for (int i = 8; i <= n; i += 2) swap(p[i], p[i + 1]);
    puts("YES");
    printf("3 6 1 5 4 7 2 ");
    for (int i = 8; i <= n; ++i) printf("%d ", p[i]);
    return;
  }
  if (n == (n & (-n))) {
    puts("NO");
    return;
  }
  for (int i = 2; i < n - 2; i += 2) swap(p[i], p[i + 1]);
  p[1] = n - 1, p[n - 2] = n, p[n - 1] = 1, p[n] = n - 2;
  puts("YES");
  for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
}
}  // namespace Subtask2
int main() {
  scanf("%d", &n);
  Subtask1::main();
  Subtask2::main();
  return 0;
}
