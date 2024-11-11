#include <bits/stdc++.h>
using namespace std;
int a[51];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  if (n == 2) {
    if (a[1] == a[2])
      puts("Bob");
    else
      puts("Alice");
    return 0;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[1]) cnt++;
  }
  if (cnt >= n / 2)
    puts("Alice");
  else
    puts("Bob");
}
