#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int t[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  sort(t, t + n);
  int wait = 0, m = 0;
  for (int i = 0; i < n; i++) {
    if (wait <= t[i]) {
      wait += t[i];
      m++;
    }
  }
  printf("%d\n", m);
  return 0;
}
