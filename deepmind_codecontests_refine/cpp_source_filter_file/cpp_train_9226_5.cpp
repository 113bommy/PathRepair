#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    bool can = false;
    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++) {
        if (3 * i + 3 * j == x) can = true;
      }
    puts(can ? "YES" : "NO");
  }
}
