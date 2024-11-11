#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int pp[maxn], mm[maxn];
char s[maxn];
int main(void) {
  int len = 0;
  char c = getchar();
  while (c != '\n') {
    s[len++] = c;
    c = getchar();
  }
  int p = 0, m = 0;
  int ans = 0;
  bool flg = false;
  for (int i = 0; i < len; i++) {
    if (s[i] == '-')
      m++;
    else if (s[i] == '+')
      p++;
    if (s[i - 2] == '=') flg = true;
    if (flg) ans = ans * 10 + s[i] - '0';
  }
  p++;
  int minn = ans + m;
  int maxx = ans * p;
  int cha = maxx - minn;
  for (int i = 0; i < p; i++) pp[i] = ans;
  for (int i = 0; i < m; i++) mm[i] = 1;
  if (cha < 0)
    cout << "Impossible" << endl;
  else {
    int t = 0;
    while (cha && t < p) {
      if (cha > pp[t]) {
        cha -= pp[t] - 1;
        pp[t] = 1;
      } else {
        pp[t] -= cha;
        cha = 0;
      }
      t++;
    }
    t = 0;
    while (cha && t < m) {
      if (cha >= ans - mm[t]) {
        cha -= ans - mm[t];
        mm[t] = ans;
      } else {
        mm[t] += cha;
        cha = 0;
      }
      t++;
    }
    if (cha)
      return cout << "Impossible" << endl, 0;
    else
      cout << "Possible" << endl;
    int tt = 0;
    t = 0;
    for (int i = 0; i < len; i++) {
      if (i == 0)
        cout << pp[i];
      else if (s[i] == '?' && s[i - 2] == '-')
        cout << mm[t++];
      else if (s[i] == '?' && s[i - 2] == '+')
        cout << pp[++tt];
      else
        cout << s[i];
    }
  }
  return 0;
}
