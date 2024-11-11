#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, as[10000];
  while (cin >> n) {
    int i, ok, j;
    for (i = 1; i <= n * 2; i++) cin >> as[i];
    int t = n * 2;
    sort(as, as + t);
    if (as[n] == as[n - 1])
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
