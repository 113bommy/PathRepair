#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  int a[100], ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1 && a[i + 1] == 0 && a[i + 2] == 1) {
      a[i + 2] = 0;
      i = i + 2;
      ans++;
    }
  }
  printf("%d", ans);
}
