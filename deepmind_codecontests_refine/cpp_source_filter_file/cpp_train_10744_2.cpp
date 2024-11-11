#include <bits/stdc++.h>
int garland(int r, int g, int b) {
  if (r == g || g == b || r == b) {
    return 1;
  } else {
    int largest = r;
    char ch = 'r';
    if (g > largest) {
      largest = g;
      ch = 'g';
    }
    if (b > largest) {
      largest = b;
      ch = 'b';
    }
    if (ch == 'r' && g + b >= r + 1) {
      return 1;
    } else if (ch == 'g' && r + b >= g + 1) {
      return 1;
    } else if (ch == 'b' && r + g >= b + 1) {
      return 1;
    } else {
      return 0;
    }
  }
}
int main() {
  int t, r, g, b;
  scanf("%d", &t);
  int ans[t];
  for (int i = 0; i < t; i++) {
    scanf("%d %d %d", &r, &g, &b);
    ans[i] = garland(r, g, b);
  }
  for (int i = 0; i < t; i++) {
    if (ans[i] == 1) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
