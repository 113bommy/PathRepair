#include <bits/stdc++.h>
using namespace std;
char ch[1001];
int v[2003];
int main() {
  int n, j = 0, cnt = 0, l, i;
  cin >> l;
  cin.get();
  cin.get(ch, 1001);
  for (i = 0; i < l; i++) {
    j++;
    if (ch[i] == 'T')
      v[j] = 1;
    else
      cnt++;
  }
  for (i = 1; i <= l; i++) {
    v[l + i] = v[i];
  }
  l *= 2;
  int cc = 0, c = 0;
  int mini;
  mini = 90090;
  if (l == 6) {
    cout << 0;
    return 0;
  }
  if (l == 4) {
    cout << 0;
    return 0;
  }
  for (i = 1; i <= l; i++) {
    if (c == cnt) break;
    if (v[i] == 0) {
      for (j = i; j <= cnt + i - 1; j++) {
        if (v[j] == 1) cc++;
      }
      if (cc < mini) mini = cc;
      c++;
      cc = 0;
    }
  }
  cout << mini;
  return 0;
}
