#include <bits/stdc++.h>
int n, k;
char b[2][100001];
struct state {
  int h;
  char wall;
  int water;
} q[200001] = {0};
char s[100001][2] = {0};
int isv(state st) {
  if (st.h < 0 || st.h <= st.water) return 0;
  if (b[st.wall][st.h] == 'X' || s[st.h][st.wall]) return 0;
  return 1;
}
int found(state st) {
  if (st.h >= n) return 1;
  return 0;
}
int main() {
  scanf("%d%d\n", &n, &k);
  gets(b[0]);
  gets(b[1]);
  int i;
  int p = 0;
  int nq = 0;
  q[0].h = 0;
  q[0].wall = 0;
  q[0].water = -1;
  s[0][0] = 1;
  nq++;
  while (p < nq) {
    state st = q[p];
    st.water++;
    if (found(st)) {
      printf("YES\n");
      return 0;
    }
    state up = st;
    up.h++;
    state down = st;
    down.h--;
    state jmp = st;
    jmp.wall = 1 - jmp.wall;
    jmp.h = jmp.h + k;
    if (isv(up)) {
      q[nq++] = up;
      s[up.h][up.wall] = 1;
    }
    if (isv(down)) {
      q[nq++] = down;
      s[down.h][down.wall] = 1;
    }
    if (isv(jmp)) {
      q[nq++] = jmp;
      s[jmp.h][jmp.wall] = 1;
    }
    p++;
  }
  printf("NO\n");
  return 0;
}
