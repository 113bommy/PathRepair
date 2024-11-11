#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long ans = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ans = (ans << 3) + (ans << 1) + (ch ^ 48);
    ch = getchar();
  }
  return ans * f;
}
int n, ans;
int j;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    for (j = 1; j * (j + 1) / 2 <= x; j++)
      ;
    ans ^= (j - 1);
  }
  if (ans) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}
