#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
char a[maxn], b[maxn];
int main() {
  int n;
  bool f1 = false, f2 = false;
  a[0] = b[0] = '@';
  while (~scanf("%d", &n)) {
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int len = n / 2, ans = 0;
    for (int i = 1; i <= len; i++) {
      int pos = n - i + 1;
      if (a[i] == a[pos] && b[i] == b[pos])
        continue;
      else if (a[i] == b[i] && a[pos] != b[pos])
        ans++;
      else if (a[i] == b[pos] && a[pos] != b[i])
        ans++;
      else if (a[pos] == b[i] && a[i] == b[pos])
        ans++;
      else if (a[pos] == b[pos] && a[i] != b[i])
        ans++;
      else {
        set<char> s;
        s.insert(a[i]);
        s.insert(b[i]);
        s.insert(a[pos]);
        s.insert(b[pos]);
        int si = s.size();
        if (si == 4)
          ans += 2;
        else if (si == 3) {
          ans += 1;
          if (a[i] == a[pos]) ans++;
        }
      }
    }
    if (n % 2 != 0) {
      if (a[n / 2 + 1] != b[n / 2 + 1]) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
