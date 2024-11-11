#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  long long a, b, c;
  for (scanf("%d", &T); T; T--) {
    cin >> a >> b >> c;
    if (a >= c) {
      printf("-1 ");
    } else
      printf("1 ");
    if (a * b > c)
      printf("%I64d\n", b);
    else
      printf("-1");
  }
  return 0;
}
