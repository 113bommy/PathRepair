#include <bits/stdc++.h>
char state[500005];
int fix_point[500005];
int fix_cnt;
int N, M, NM;
int main() {
  int i, j, k, x, y, f, cnt = 0, m = (1e6) + 3;
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
        if (state[x] & (1 << (1 + (f ^ 2)))) {
          printf("0\n");
          return 0;
        } else if (state[x] & (1 << (1 + f))) {
          state[x] |= (1 << 4);
        } else {
          if (is_first) {
            state[x] |= (1 << 6);
            cnt++;
          } else if ((state[x] & (1 << 6))) {
            cnt--;
          }
          state[x] |= (1 << (1 + f));
        }
      }
      j = (k + M - 1) / M * M;
      f = ((c & (1 << 1)) ? 2 : 0);
      for (x = k + 1; x < j; x++, f ^= 2) {
        if (state[x] & (1 << (1 + (f ^ 2)))) {
          printf("0\n");
          return 0;
        } else if (state[x] & (1 << (1 + f))) {
          state[x] |= (1 << 4);
        } else {
          if (is_first) {
            state[x] |= (1 << 6);
            cnt++;
          } else if ((state[x] & (1 << 6))) {
            cnt--;
          }
          state[x] |= (1 << (1 + f));
        }
      }
    }
    if (!(c & (1 << 5))) {
      y = k / M;
      j = 1;
      f = ((c & 1) ? 2 : 0);
      for (y = k - M; y >= 0; y -= M, f ^= 2) {
        if ((state[y] & (1 << (f ^ 2)))) {
          printf("0\n");
          return 0;
        } else if (state[y] & (1 << f)) {
          state[y] |= (1 << 5);
        } else {
          if (is_first) {
            state[y] |= (1 << 6);
            cnt++;
          } else if ((state[y] & (1 << 6))) {
            cnt--;
          }
          state[y] |= (1 << f);
        }
      }
      f = ((c & 1) ? 2 : 0);
      for (y = k + M; y < NM; y += M, f ^= 2) {
        if ((state[y] & (1 << (f ^ 2)))) {
          printf("0\n");
          return 0;
        } else if (state[y] & (1 << f)) {
          state[y] |= (1 << 5);
        } else {
          if (is_first) {
            state[y] |= (1 << 6);
            cnt++;
          } else if ((state[y] & (1 << 6))) {
            cnt--;
          }
          state[y] |= (1 << f);
        }
      }
    }
    is_first = false;
  }
  int ret = 1;
  j = fix_cnt > 0 ? cnt : N + M;
  for (i = 0; i < j; i++) {
    ret *= 2;
    ret %= m;
  }
  printf("%d\n", ret);
  return 0;
}
