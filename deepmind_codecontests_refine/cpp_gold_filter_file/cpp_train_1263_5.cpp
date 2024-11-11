#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  int n, k;
  cin >> k >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (k % 2 == 0) {
    if (a[n] % 2 == 1) {
      printf("odd\n");
    } else
      printf("even\n");
  } else {
    int s1 = 0, s2 = n;
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 0) {
        s1++;
        s2--;
      }
    }
    if (s2 % 2) {
      printf("odd\n");
    } else
      printf("even\n");
  }
  return 0;
}
