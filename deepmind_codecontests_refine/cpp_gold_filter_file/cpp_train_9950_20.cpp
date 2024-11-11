#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100010], b[100010];
  int ka, kb, f[100010], l[100010], i, cnt, flag, be, end, ans;
  cin >> a >> b;
  ka = strlen(a);
  kb = strlen(b);
  cnt = kb - 1;
  for (i = ka - 1; i >= 0; i--)
    if (a[i] == b[cnt] && cnt >= 0) l[cnt--] = i;
  flag = cnt;
  for (i = 0; i <= cnt; i++) l[i] = -1;
  cnt = 0;
  for (i = 0; i < ka; i++)
    if (a[i] == b[cnt] && cnt < kb) f[cnt++] = i;
  for (i = cnt; i < kb; i++) f[i] = ka;
  ans = flag + 1;
  be = 0;
  end = flag;
  for (i = 1; i < kb && f[0] != ka && flag != -1; i++) {
    while (flag < kb && f[i - 1] >= l[flag]) flag++;
    if (f[i] == ka) {
      if (ans > flag - i) {
        ans = flag - i;
        be = i;
        end = flag - 1;
      }
      break;
    }
    if (flag >= kb - 1) {
      if (ans > kb - i) {
        ans = kb - i;
        be = i;
        end = kb - 1;
      }
      continue;
    }
    if (ans > flag - i) {
      ans = flag - i;
      be = i;
      end = flag - 1;
    }
  }
  if (ans == kb)
    cout << "-" << endl;
  else if (flag == -1)
    cout << b << endl;
  else {
    for (i = 0; i < be; i++) cout << b[i];
    for (i = end + 1; i < kb; i++) cout << b[i];
    cout << endl;
  }
}
