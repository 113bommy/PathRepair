#include <bits/stdc++.h>
bool cmp(const int &a, const int &b) { return (a < b); }
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int main() {
  int a[3], b[3], c[3];
  scanf("%d%d%d", &a[0], &a[1], &a[2]);
  std::sort(a, a + 3, cmp);
  for (int i = 0; i < 3; i++) {
    b[i] = a[i];
    c[i] = a[i];
  }
  int ans1 = 0, ans2 = 0, ans3 = 0;
  if (a[0] >= 2) {
    for (int i = 0; i < 3; i++) {
      b[i] -= 1;
      c[i] -= 2;
    }
    ans1 += 1;
    ans2 += 2;
  }
  for (int i = 0; i < 3; i++) {
    ans1 += b[i] / 3;
    ans2 += c[i] / 3;
    ans3 += a[i] / 3;
  }
  printf("%d\n", max(max(ans1, ans2), ans3));
  return 0;
}
