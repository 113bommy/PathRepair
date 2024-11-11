#include <bits/stdc++.h>
using namespace std;
struct yash {
  int a;
  int b;
};
bool cmp(struct yash p, struct yash p1) {
  if (p.a < p1.a) {
    return true;
  } else if (p.a > p1.a) {
    return false;
  } else {
    if (p.b < p1.b) {
      return true;
    } else {
      return false;
    }
  }
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  struct yash y[n];
  int x[n];
  int cc[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    y[i].b = i;
    y[i].a = x[i];
  }
  sort(y, y + n, cmp);
  for (int i = 0; i < n; i++) {
    cc[y[i].b] = i;
  }
  int ans = 0;
  int st = 0;
  for (int i = 0; i < n; i++) {
    int k = i;
    int j = 0;
    for (j = i + 1; j <= cc[k]; j++) {
      if (x[j] >= x[k]) {
        k = j;
      }
    }
    ans++;
    i = j - 1;
  }
  printf("%d\n", ans);
}
