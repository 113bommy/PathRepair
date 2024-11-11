#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
char s[maxn];
int a[maxn], p[maxn], su[maxn];
int main() {
  int n;
  cin >> n;
  scanf("%s", s + 1);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(')
      x++;
    else
      x--;
    a[i] = x;
  }
  for (int i = 1; i <= n; i++) {
    if (i != 1)
      p[i] = min(a[i], p[i - 1]);
    else
      p[i] = a[i];
  }
  for (int i = n; i >= 1; i--) {
    if (i != n)
      su[i] = min(a[i], su[i + 1]);
    else
      su[i] = a[i];
  }
  if (x != 2 && x != -2) {
    cout << 0 << endl;
    return 0;
  } else {
    int ans = 0;
    if (x == 2) {
      for (int i = 1; i <= n; i++) {
        if (s[i] == '(' && p[i] >= 0 && su[i] >= 2) ans++;
      }
    } else {
      for (int i = 1; i <= n; i++) {
        if (i != 1 && s[i] == ')' && p[i - 1] >= 0 && a[i] >= -1 && su[i] >= -2)
          ans++;
        else if (i == 1 && s[i] == ')' && su[i] >= -2)
          ans++;
      }
    }
    cout << ans << endl;
    return 0;
  }
}
