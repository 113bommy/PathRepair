#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int Max = 1e9 + 5;
char a[maxn], b[maxn];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    scanf("%s %s", a, b);
    int cnt = 0;
    if (n % 2 == 1) {
      if (a[n / 2] != b[n / 2]) cnt++;
    }
    for (int i = 0; i < n / 2; i++) {
      if (a[i] == a[n - i - 1] && b[i] == b[n - i - 1]) {
        continue;
      } else if (a[i] == b[n - i - 1] && b[i] == a[n - i - 1]) {
        continue;
      } else if (a[i] == b[i] && a[n - i - 1] == b[n - i - 1]) {
        continue;
      } else if (a[i] == b[n - i - 1] || a[n - i - 1] == b[i] || a[i] == b[i] ||
                 a[n - i - 1] == b[n - i - 1] || b[i] == b[n - i - 1])
        cnt++;
      else
        cnt += 2;
    }
    cout << cnt << endl;
  }
  return 0;
}
