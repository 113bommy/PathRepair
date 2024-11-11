#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
char ch[200010];
int main() {
  int n = read(), t = read();
  scanf("%s", ch + 1);
  int st = 0;
  for (int i = 1; i <= n; i++)
    if (ch[i] == '.') st = i + 1;
  if (st == 0 || st == n + 1) {
    int ed = (st == 0 ? n : n - 1);
    while (ch[ed] == '0' && ed >= st || ch[ed] == '.') ed--;
    for (int i = 1; i <= ed; i++) {
      printf("%c", ch[i]);
    }
    return 0;
  }
  int qt = 0;
  for (int i = st; i <= n; i++) {
    if (ch[i] > '4') {
      qt = i;
      break;
    }
  }
  if (!qt) {
    int ed = n;
    while (ch[ed] == '0' && ed >= st || ch[ed] == '.') ed--;
    for (int i = 1; i <= ed; i++) {
      printf("%c", ch[i]);
    }
    return 0;
  }
  int cnt = 0;
  for (int i = qt - 1; i >= st; i--) {
    if (ch[i] == '4')
      cnt++;
    else
      break;
  }
  t--;
  if (t >= cnt) {
    int stt = 1;
    int rt = (st == qt - cnt ? qt - cnt - 2 : qt - cnt - 1);
    ch[rt]++;
    while (ch[rt] == '9' + 1) {
      ch[rt] = '0';
      ch[rt - 1]++;
      if (rt == st) ch[rt - 1]--, ch[rt - 2]++, rt--;
      rt--;
    }
    if (rt == 0) stt = rt;
    int ed = (qt - cnt == st ? st - 2 : qt - cnt - 1);
    while (ch[ed] == '0' && ed >= st || ch[ed] == '.') ed--;
    if (ch[stt] == '?') ch[stt] = '1';
    for (int i = stt; i <= ed; i++) {
      printf("%c", ch[i]);
    }
  } else {
    int stt = 1;
    int rt = (st == qt - t ? qt - t - 2 : qt - t - 1);
    ch[rt]++;
    while (ch[rt] == '9' + 1) {
      ch[rt] = '0';
      ch[rt - 1]++;
      if (rt == st) ch[rt - 1]--, ch[rt - 2]++, rt--;
      rt--;
    }
    if (rt == 0) stt = rt;
    int ed = (qt - t == st ? st - 2 : qt - t - 1);
    while (ch[ed] == '0' && ed >= st || ch[ed] == '.') ed--;
    if (ch[stt] == '?') ch[stt] = '1';
    for (int i = stt; i <= ed; i++) {
      printf("%c", ch[i]);
    }
  }
  return 0;
}
