#include <bits/stdc++.h>
using namespace std;
struct RTC {};
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  vector<int> ans;
  int y = 0, num = 0;
  for (int it = 0; it < (n - 1); it++) {
    ans.push_back(num);
    y ^= num;
    num++;
  }
  y = y ^ x;
  if (y >= num) {
    ans.push_back(y);
  } else {
    bool ok = false;
    int cp = 32 - __builtin_clz(y);
    for (int i = 0; i < (((int)(ans).size())); i++)
      if (i != y) {
        ans[i] |= (1 << cp);
        y |= (1 << cp);
        ok = true;
        break;
      }
    if (ok)
      ans.push_back(y);
    else {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (int e : ans) printf("%d ", e);
  putchar('\n');
  return 0;
}
