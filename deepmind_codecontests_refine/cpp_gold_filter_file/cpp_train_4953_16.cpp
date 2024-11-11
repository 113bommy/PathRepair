#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, k;
int main() {
  cin >> n >> k;
  if (k == 1 || k >= 4) return puts("-1"), 0;
  if (k == 2) {
    if (n < 5) return puts("-1"), 0;
    printf("%d\n", n - 1);
    for (int i = 1; i < n; i++) printf("%d %d\n", i, i + 1);
  } else if (k == 3) {
    if (n < 4) return puts("-1"), 0;
    printf("%d\n", n - 1);
    for (int i = 1; i < n - 1; i++) printf("%d %d\n", 1, i + 1);
    printf("%d %d\n", n - 1, n);
  }
  return 0;
}
