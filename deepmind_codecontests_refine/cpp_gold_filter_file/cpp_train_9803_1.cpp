#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n;
  scanf("%d", &n);
  memset(a, -1, sizeof(int) * 100005);
  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == -1) {
      for (int j = i; j <= n; j += i) {
        if (a[j] == -1) a[j] = cnt;
      }
      cnt++;
    }
  }
  for (int i = 2; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
