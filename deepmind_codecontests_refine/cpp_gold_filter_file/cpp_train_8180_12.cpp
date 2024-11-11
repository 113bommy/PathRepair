#include <bits/stdc++.h>
using namespace std;
int n;
inline void put(int a, int b) { printf("%d %d\n", a, b); }
int main() {
  scanf("%d", &n);
  if (n % 4 >= 2) return puts("NO"), 0;
  puts("YES");
  bool flag = n % 4;
  for (int i = 1; i + 3 <= n; i += 4) {
    if (flag) put(i, n);
    put(i, i + 1);
    if (flag) put(i + 1, n);
    if (flag) put(i + 2, n);
    put(i + 2, i + 3);
    if (flag) put(i + 3, n);
    put(i + 1, i + 2);
    put(i, i + 3);
    put(i, i + 2);
    put(i + 1, i + 3);
  }
  for (int i = 1; i + 3 <= n; i += 4)
    for (int j = i + 4; j + 3 <= n; j += 4) {
      put(i, j), put(i + 1, j + 1), put(i + 2, j + 2), put(i + 3, j + 3);
      put(i, j + 1), put(i + 1, j + 2), put(i + 2, j + 3), put(i + 3, j);
      put(i, j + 3), put(i + 1, j), put(i + 2, j + 1), put(i + 3, j + 2);
      put(i, j + 2), put(i + 1, j + 3), put(i + 2, j), put(i + 3, j + 1);
    }
  return 0;
}
