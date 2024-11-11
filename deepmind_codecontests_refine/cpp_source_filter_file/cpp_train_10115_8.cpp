#include <bits/stdc++.h>
char state[500005];
int fix_point[500005];
int fix_cnt, cnt;
int N, M, NM;
bool func(int p, int a, int b, int f, bool is_first) {
  if (state[p] & (1 << (a + (f ^ 2)))) {
    printf("0\n");
    return false;
  } else if (state[p] & (1 << (a + f))) {
    state[p] |= (1 << b);
  } else {
    if (is_first) {
      state[p] |= (1 << 6);
      cnt++;
    } else if ((state[p] & (1 << 6))) {
      cnt--;
    }
    state[p] |= (1 << (a + f));
  }
  return true;
}
int main() {
  int i, j, k, x, y, f, m = (1e6) + 3;
  char c;
  scanf("%d %d", &N, &M);
  getchar();
  NM = N * M;
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      scanf("%c", &c);
      if (c == '.') continue;
      k = i * M + j;
      fix_point[fix_cnt++] = k;
      if (c == '1')
        state[k] = 0x3;
      else if (c == '2')
        state[k] = 0x6;
      else if (c == '3')
        state[k] = 0xC;
      else
        state[k] = 0x9;
    }
    getchar();
  }
  bool is_first = true;
  for (i = 0; i < fix_cnt; i++) {
    k = fix_point[i];
    c = state[k];
    if (!(c & (1 << 4))) {
      j = k - (k % M);
      f = ((c & (1 << 1)) ? 2 : 0);
      for (x = k - 1; x >= j; x--, f ^= 2) {
        if (!func(x, 1, 4, f, is_first)) return 0;
      }
      j = (k + 1 + M - 1) / M * M;
      f = ((c & (1 << 1)) ? 2 : 0);
      for (x = k + 1; x < j; x++, f ^= 2) {
        if (!func(x, 1, 4, f, is_first)) return 0;
      }
    }
    if (!(c & (1 << 5))) {
      y = k / M;
      j = 1;
      f = ((c & 1) ? 2 : 0);
      for (y = k - M; y >= 0; y -= M, f ^= 2) {
        if (!func(y, 0, 5, f, is_first)) return 0;
      }
      f = ((c & 1) ? 2 : 0);
      for (y = k + M; y < NM; y += M, f ^= 2) {
        if (!func(y, 0, 5, f, is_first)) return 0;
      }
    }
    is_first = false;
  }
  int ret = 1;
  j = fix_cnt > 0 ? cnt : N + M;
  for (i = 0; i < j; i++) {
    ret <<= 2;
    if (ret > m) ret %= m;
  }
  printf("%d\n", ret);
  return 0;
}
