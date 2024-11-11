#include <bits/stdc++.h>
int MOD = int(1e9) + 7;
inline int add(int a, int b) {
  return (a + b >= MOD) ? (a + b - MOD) : (a + b);
}
inline void inc(int &a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return (a - b < 0) ? (a - b + MOD) : (a - b); }
inline void dec(int &a, int b) { a = sub(a, b); }
inline int mul(int a, int b) { return (a * 1ll * b) % MOD; }
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a % 2)
      y++;
    else
      x++;
  }
  int player = 0;
  for (; player < n - k - 1; player++) {
    if (player % 2 == 0) {
      if (x)
        x--;
      else
        y--;
    } else if (y)
      y--;
    else
      x--;
  }
  string A = "Stannis", B = "Daenerys", ans;
  if (k == n)
    ans = y ? A : B;
  else if (!y)
    ans = B;
  else if (!x) {
    y--;
    ans = y % 2 ? A : B;
  } else
    ans = player % 2 ? B : A;
  cout << ans << endl;
  return 0;
}
