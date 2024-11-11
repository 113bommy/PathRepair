#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 200000 + 10;
const int mod = 1000000007;
set<int> s;
int main() {
  int a[101000], b[3], n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s.insert(a[i]);
  }
  int ans = 0;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) b[ans++] = *it;
  sort(b, b + ans);
  if (ans == 1 || (ans == 2 && b[ans - 1] - b[0] != 2)) {
    printf("%d\n", n);
    for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
  } else {
    int sum = 0;
    sort(a, a + n);
    if (s.size() == 2) {
      for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (a[i] != a[j]) {
          a[i]++;
          a[j]--;
          sum += 2;
        } else
          break;
      }
    } else {
      int x = 0, y = 0, z = 0;
      int cnt = -1;
      for (int i = 0; i < n; i++) {
        if (a[i] == b[0])
          x++;
        else if (a[i] == b[1]) {
          if (cnt == -1) cnt = i;
          y++;
        } else
          z++;
      }
      if (y / 2 > min(x, z)) {
        for (int i = cnt; i < n; i += 2) {
          if (a[i] != a[i + 1]) break;
          a[i]--;
          a[i + 1]++;
          sum += 2;
        }
      } else {
        for (int i = 0, j = n - 1; i < j; i++, j--) {
          if (a[i] != a[j] && a[i] + 2 == a[j]) {
            a[i]++;
            a[j]--;
            sum += 2;
          } else
            break;
        }
      }
    }
    printf("%d\n", n - sum);
    for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
  }
  return 0;
}
