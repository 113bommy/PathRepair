#include <bits/stdc++.h>
using namespace std;
const int maxn = 256;
int input[maxn], n;
bool check() {
  if (n == 1) return true;
  int z = 0, f = 0, u = 0;
  input[n + 1] = input[1];
  for (int i = 1; i <= n; i++) {
    int up = input[i + 1] - input[i];
    if (up == 1)
      z++;
    else if (up == -1)
      f++;
    else if (abs(up) == n - 1)
      u++;
    else
      return false;
  }
  if (max(z, f) == n - 1 && u == 1) return true;
  return false;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &input[i]);
    printf("%s\n", check() ? "YES" : "NO");
  }
  return 0;
}
