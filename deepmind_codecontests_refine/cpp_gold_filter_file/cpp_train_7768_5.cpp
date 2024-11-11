#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000005;
long long n, x;
int main() {
  scanf("%lld%lld", &n, &x);
  x -= n - 1;
  for (int i = (1); i < (n + 1); i++) {
    int d;
    scanf("%d", &d);
    x -= d;
  }
  if (x == 0)
    puts("YES");
  else
    puts("NO");
  return 0;
}
