#include <bits/stdc++.h>
using namespace std;
struct S {
  long long x, y;
} ss[100010];
bool cmp(S a, S b) { return a.x < b.x; }
int main() {
  long long s, n;
  while (cin >> s >> n) {
    for (int i = 1; i <= n; i++) cin >> ss[i].x >> ss[i].y;
    sort(ss + 1, ss + 1 + n, cmp);
    bool f = 1;
    for (int i = 1; i <= n; i++) {
      if (s < ss[i].x) {
        f = 0;
        break;
      } else {
        s += ss[i].y;
      }
    }
    if (f)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
