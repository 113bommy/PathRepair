#include <bits/stdc++.h>
using namespace std;
char c[102];
char s[102];
char pos[102];
int lenpos, lens;
bool vst[102];
int n, k;
bool prejd() {
  for (int i = 0; i < lenpos; ++i) {
    if (pos[i] == '1') {
      for (int j = 0; j < lens; ++j) {
        if (i + j >= n) return 0;
        if (vst[i + j]) {
          if (c[i + j] != s[j]) return 0;
        } else {
          c[i + j] = s[j];
          vst[i + j] = 1;
        }
      }
    }
  }
  for (int i = 0; i < lenpos; ++i) {
    if (pos[i] == '0') {
      bool flag = 0;
      for (int j = 0; j < lens; ++j) {
        if (!vst[i + j] || c[i + j] != s[j]) {
          flag = 1;
          break;
        }
      }
      if (!flag) return 0;
    }
  }
  return 1;
}
bool solve() {
  for (int i = 0; i < n - lens + 2; ++i) {
    if (pos[i] == '0') {
      int j = 0;
      for (; j < lens; j++) {
        if (vst[i + j]) {
          if (c[i + j] != s[j]) break;
        } else {
          for (char C = 'a'; C < 'a' + k; C++)
            if (C != s[j]) {
              c[i + j] = C;
              vst[i + j] = 1;
              break;
            }
          if (vst[i + j]) break;
        }
      }
      if (j == lens) return 0;
    }
  }
  return 1;
}
int main() {
  memset(vst, 0, sizeof(vst));
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  scanf("%s", pos);
  lenpos = strlen(pos);
  lens = strlen(s);
  if (!prejd())
    puts("No solution");
  else {
    if (solve()) {
      for (int i = 0; i < n; ++i) {
        if (!vst[i]) c[i] = 'a';
      }
      c[n] = '\0';
      puts(c);
    } else {
      puts("No solution");
    }
  }
  return 0;
}
