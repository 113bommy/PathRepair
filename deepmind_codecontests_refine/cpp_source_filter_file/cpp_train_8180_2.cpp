#include <bits/stdc++.h>
using namespace std;
int n;
void o(int x, int y) { printf("%d %d\n", x, y); }
int main() {
  scanf("%d", &n);
  if (n % 4 > 1) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = n % 4; i < n; i += 4) {
    for (int j = 0; j < i; j++) o(j + 1, i + 1);
    o(i + 1, i + 2);
    for (int j = i - 1; ~j; j--) o(j + 1, j + 2);
    for (int j = 0; j < i; j++) o(j + 1, j + 3);
    o(i + 3, i + 4);
    for (int j = i - 1; ~j; j--) o(j + 1, j + 4);
    o(i + 1, i + 4);
    o(i + 2, i + 3);
    o(i + 1, i + 3);
    o(i + 2, i + 4);
  }
  return 0;
}
