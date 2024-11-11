#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
char s[MAXN];
int a[MAXN], n;
string ans, tmp;
int b[MAXN], m;
void Update() {
  tmp.clear();
  int i;
  for (i = 1; i <= m && !b[i]; i++)
    ;
  if (i < m + 1) {
    for (i; i <= m; i++) tmp += b[i] + '0';
  } else if (m)
    tmp += '0';
  if (ans.length() < tmp.length()) ans = tmp;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
  int sum = 0;
  for (int i = 1; i <= n; i++) sum = (sum + a[i] % 3) % 3;
  if (!sum) {
    m = 0;
    for (int i = 1; i <= n; i++) b[++m] = a[i];
    Update();
  } else {
    int p1 = 0, p2 = 0;
    for (int i = n; i > 0 && !p1; i--)
      if (a[i] % 3 == sum) p1 = i;
    if (p1) {
      m = 0;
      for (int i = 1; i <= n; i++) {
        if (i == p1) continue;
        b[++m] = a[i];
      }
      Update();
    }
    p1 = p2 = 0;
    for (int i = n; i > 0 && (!p1 || !p2); i--)
      if (a[i] % 3 + sum == 3) p1 ? p2 = i : p1 = i;
    if (p1 && p2) {
      m = 0;
      for (int i = 1; i <= n; i++) {
        if (i == p1 || i == p2) continue;
        b[++m] = a[i];
      }
      Update();
    }
  }
  if (!ans.length()) {
    bool flag = 0;
    for (int i = 1; i <= n; i++)
      if (!a[i]) flag = 1;
    puts(flag ? "0" : "-1");
  } else
    cout << ans << endl;
}
