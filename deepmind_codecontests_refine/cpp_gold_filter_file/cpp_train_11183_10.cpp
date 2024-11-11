#include <bits/stdc++.h>
using namespace std;
int n, a[1000], t, s;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%d", &t);
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (a[j] - a[i] <= t && j - i + 1 > s) s = j - i + 1;
    }
  }
  printf("%d", s);
  scanf("\n");
}
