#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, sum = 0, notpissedoffpeeps = 0;
  scanf("%d", &n);
  int t[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  sort(t, t + n);
  for (i = 0; i < n; i++) {
    if (sum <= t[i]) {
      notpissedoffpeeps++;
      sum += t[i];
    }
  }
  printf("%d", notpissedoffpeeps);
  return 0;
}
