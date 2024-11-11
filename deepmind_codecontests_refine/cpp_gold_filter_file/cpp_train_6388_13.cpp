#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
int T, n;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", max(0, n - 2));
  }
  return 0;
}
