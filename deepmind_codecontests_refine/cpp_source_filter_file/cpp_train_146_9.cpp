#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, a, b, ok = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x == 100)
      a++;
    else {
      b++;
    }
  }
  b = (b & 1);
  if (b) a -= 2;
  if (a < 0) ok = 0;
  if (a & 1) ok = 0;
  puts(ok ? "YES" : "NO");
}
