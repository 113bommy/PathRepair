#include <bits/stdc++.h>
int mask[1 << 20];
int stack[1000];
int stack2[1000];
int top = 0;
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (!mask[a]) {
      mask[a] = i + 1;
      ans++;
    }
    int top2 = 0;
    stack2[top2++] = a;
    for (int z = 0; z < top; z++) {
      if (mask[stack[z] | a] != i + 1) {
        stack2[top2++] = stack[z] | a;
        if (!mask[stack[z] | a]) ans++;
        mask[stack[z] | a] = i + 1;
      }
    }
    for (int i = 0; i < top2; i++) stack[i] = stack2[i];
    top = top2;
  }
  printf("%d\n", ans);
}
