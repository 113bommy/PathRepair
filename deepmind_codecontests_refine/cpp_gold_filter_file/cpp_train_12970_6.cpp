#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
char s[MAXN];
int a[MAXN];
int n;
string ans;
void solve(int st) {
  int sum = 0;
  for (int i = st; i <= n; i++) sum = (sum + a[i]) % 3;
  string tmp;
  if (!sum) {
    for (int i = st; i <= n; i++) tmp += a[i] + '0';
    if (tmp.length() > ans.length()) ans = tmp;
    return;
  }
  for (int i = st + 1; i <= n; i++) {
    if (sum == a[i] % 3) {
      for (int j = st; j <= n; j++)
        if (j != i) tmp += a[j] + '0';
      if (tmp.length() > ans.length()) ans = tmp;
      return;
    }
  }
  int last = 0;
  for (int i = st + 1; i <= n; i++) {
    if ((sum + a[i] % 3) == 3) {
      if (last) {
        for (int j = st; j <= n; j++)
          if (j != last && j != i) tmp += a[j] + '0';
        if (tmp.length() > ans.length()) ans = tmp;
        return;
      } else
        last = i;
    }
  }
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
  int s1, s2, s3;
  s1 = s2 = s3 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      if (s1 && s2 && s3) continue;
      if (s1 && s2)
        s3 = i;
      else if (s1)
        s2 = i;
      else
        s1 = i;
    }
  }
  if (s1) solve(s1);
  if (s2) solve(s2);
  if (s3) solve(s3);
  if (ans.length())
    cout << ans << endl;
  else {
    bool flag = 0;
    for (int i = 1; i <= n; i++)
      if (!a[i]) flag = 1;
    if (flag)
      puts("0");
    else
      puts("-1");
  }
}
