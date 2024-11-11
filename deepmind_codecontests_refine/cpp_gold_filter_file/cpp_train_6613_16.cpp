#include <bits/stdc++.h>
using namespace std;
const int maxs = 1 << 20;
int cnt, f[maxs], trans[maxs], q[30];
void add(int s) { trans[++cnt] = s; }
void add(int lower, int upper) {
  for (int a = lower; a <= upper; a++) {
    int s = 0;
    for (int b = a; b <= upper; b++) {
      s |= 1 << q[b];
      add(s);
    }
  }
}
void init() {
  for (int a = 1; a <= 19; a++) q[a]--;
  add(1, 3);
  add(4, 7);
  add(8, 12);
  add(13, 16);
  add(17, 19);
}
void pre() {
  for (int a = 1; a <= 19; a++) q[a] = a;
  init();
  q[1] = 1;
  q[2] = 4;
  q[3] = 8;
  q[4] = 2;
  q[5] = 5;
  q[6] = 9;
  q[7] = 13;
  q[8] = 3;
  q[9] = 6;
  q[10] = 10;
  q[11] = 14;
  q[12] = 17;
  q[13] = 7;
  q[14] = 11;
  q[15] = 15;
  q[16] = 18;
  q[17] = 12;
  q[18] = 16;
  q[19] = 19;
  init();
  q[1] = 8;
  q[2] = 13;
  q[3] = 17;
  q[4] = 4;
  q[5] = 9;
  q[6] = 14;
  q[7] = 18;
  q[8] = 1;
  q[9] = 5;
  q[10] = 10;
  q[11] = 15;
  q[12] = 19;
  q[13] = 2;
  q[14] = 6;
  q[15] = 11;
  q[16] = 16;
  q[17] = 3;
  q[18] = 7;
  q[19] = 12;
  init();
}
bool dfs(int now) {
  if (f[now] != -1) return f[now];
  for (int a = 1; a <= cnt; a++)
    if ((now & trans[a]) == trans[a]) {
      if (!dfs(now - trans[a])) {
        f[now] = 1;
        return true;
      }
    }
  f[now] = 0;
  return false;
}
int main() {
  pre();
  int nows = 0;
  for (int a = 0; a < 19; a++) {
    char s[2];
    scanf("%s", s);
    if (s[0] == 'O') nows |= 1 << a;
  }
  memset(f, -1, sizeof(f));
  if (dfs(nows))
    printf("Karlsson\n");
  else
    printf("Lillebror\n");
  return 0;
}
