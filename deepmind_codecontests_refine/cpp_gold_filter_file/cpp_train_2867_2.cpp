#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, k, a, b, c, d;
bool used[4 * N];
int main() {
  scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &d);
  if (n <= 4 || n >= k) {
    puts("-1");
    return 0;
  }
  used[a] = used[b] = used[c] = used[d] = 1;
  int ptr = 1, out = 4;
  printf("%d %d ", a, c);
  while (out <= n - 1) {
    if (used[ptr]) {
      ptr++;
      continue;
    }
    printf("%d ", ptr);
    out++;
    ptr++;
  }
  printf("%d %d ", d, b);
  puts("");
  ptr = 1, out = 4;
  printf("%d %d ", c, a);
  while (out <= n - 1) {
    if (used[ptr]) {
      ptr++;
      continue;
    }
    printf("%d ", ptr);
    out++;
    ptr++;
  }
  printf("%d %d ", b, d);
  puts("");
  return 0;
}
