#include <bits/stdc++.h>
using namespace std;
char Buff[(1 << 18)], *_S = Buff, *_T = Buff;
template <typename T>
T read(void) {
  char c = (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, (1 << 18), stdin),
                         _S == _T)
                ? EOF
                : *_S++);
  T f = 1, num = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = (_S == _T &&
                 (_T = (_S = Buff) + fread(Buff, 1, (1 << 18), stdin), _S == _T)
             ? EOF
             : *_S++);
  }
  while ('0' <= c && c <= '9') {
    num = (num << 3) + (num << 1) + (c ^ 48);
    c = (_S == _T &&
                 (_T = (_S = Buff) + fread(Buff, 1, (1 << 18), stdin), _S == _T)
             ? EOF
             : *_S++);
  }
  return f * num;
}
int record[200005];
int main() {
  int n = read<int>(), s = read<int>();
  int cnt = 0, ans = 0;
  for (register int i = 1, d; i <= n; i++) {
    d = read<int>();
    if (i == s)
      ans = (d != 0);
    else
      record[d]++;
  }
  for (register int i = 1; cnt < n; i++) {
    cnt += record[i] ? record[i] : 1;
    ans += (record[i] == 0);
  }
  printf("%d\n", ans);
  return 0;
}
