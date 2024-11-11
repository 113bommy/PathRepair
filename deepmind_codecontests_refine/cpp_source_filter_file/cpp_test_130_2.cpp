#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, c = getchar();
  bool f = 0;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 1;
  for (; isdigit(c); c = getchar()) x = x * 10 + (c & 15);
  return f ? -x : x;
}
const int N = (int)1e4 + 5;
int typ[N], ans[N];
void work() {
  int n = gi();
  for (int i = 1; 3 * i <= n; ++i) {
    printf("? %d %d %d\n", 3 * i - 2, 3 * i - 1, 3 * i), fflush(stdout);
    typ[i] = gi();
  }
  for (int i = 1; 3 * i < n; ++i) {
    if (typ[i] != typ[i + 1]) {
      int good = 0, bad = 0;
      if (typ[i] == 0 && typ[i + 1] == 1) {
        printf("? %d %d %d\n", 3 * i - 1, 3 * i, 3 * i + 1), fflush(stdout);
        int t1 = gi();
        printf("? %d %d %d\n", 3 * i, 3 * i + 1, 3 * i + 2), fflush(stdout);
        int t2 = gi();
        if (t1 == 0 && t2 == 0) {
          bad = 3 * i, good = 3 * i + 3;
          ans[bad] = 0, ans[good] = 1;
          printf("? %d %d %d\n", bad, good, 3 * i + 1), fflush(stdout);
          ans[3 * i + 1] = gi();
          ans[3 * i + 2] = 1 - ans[3 * i + 1];
          printf("? %d %d %d\n", bad, good, 3 * i - 2), fflush(stdout);
          ans[3 * i - 2] = gi();
          printf("? %d %d %d\n", bad, good, 3 * i - 1), fflush(stdout);
          ans[3 * i - 1] = gi();
        }
        if (t1 == 1 && t2 == 1) {
          bad = 3 * i - 2, good = 3 * i + 1;
          ans[bad] = 0, ans[good] = 1;
          printf("? %d %d %d\n", bad, good, 3 * i - 1), fflush(stdout);
          ans[3 * i - 1] = gi();
          ans[3 * i] = 1 - ans[3 * i - 1];
          printf("? %d %d %d\n", bad, good, 3 * i + 2), fflush(stdout);
          ans[3 * i + 2] = gi();
          printf("? %d %d %d\n", bad, good, 3 * i + 3), fflush(stdout);
          ans[3 * i + 3] = gi();
        }
        if (t1 == 0 && t2 == 1) {
          bad = 3 * i - 1, good = 3 * i + 2;
          ans[bad] = 0, ans[good] = 1;
          printf("? %d %d %d\n", bad, good, 3 * i), fflush(stdout);
          ans[3 * i] = gi();
          ans[3 * i + 1] = 1 - ans[3 * i];
          printf("? %d %d %d\n", bad, good, 3 * i - 2), fflush(stdout);
          ans[3 * i - 2] = gi();
          printf("? %d %d %d\n", bad, good, 3 * i + 3), fflush(stdout);
          ans[3 * i + 3] = gi();
        }
        if (t1 == 1 && t2 == 0) {
          bad = 3 * i - 2, good = 3 * i - 1;
          ans[3 * i - 2] = 0, ans[3 * i - 1] = 1, ans[3 * i] = 0,
                      ans[3 * i + 1] = 1, ans[3 * i + 2] = 0,
                      ans[3 * i + 3] = 1;
        }
      }
      if (typ[i] == 1 && typ[i + 1] == 0) {
        printf("? %d %d %d\n", 3 * i - 1, 3 * i, 3 * i + 1), fflush(stdout);
        int t1 = gi();
        printf("? %d %d %d\n", 3 * i, 3 * i + 1, 3 * i + 2), fflush(stdout);
        int t2 = gi();
        if (t1 == 1 && t2 == 1) {
          good = 3 * i, bad = 3 * i + 3;
          ans[bad] = 0, ans[good] = 1;
          printf("? %d %d %d\n", bad, good, 3 * i + 1), fflush(stdout);
          ans[3 * i + 1] = gi();
          ans[3 * i + 2] = 1 - ans[3 * i + 1];
          printf("? %d %d %d\n", bad, good, 3 * i - 2), fflush(stdout);
          ans[3 * i - 2] = gi();
          printf("? %d %d %d\n", bad, good, 3 * i - 1), fflush(stdout);
          ans[3 * i - 1] = gi();
        }
        if (t1 == 0 && t2 == 0) {
          good = 3 * i - 2, bad = 3 * i + 1;
          ans[bad] = 0, ans[good] = 1;
          printf("? %d %d %d\n", bad, good, 3 * i - 1), fflush(stdout);
          ans[3 * i - 1] = gi();
          ans[3 * i] = 1 - ans[3 * i - 1];
          printf("? %d %d %d\n", bad, good, 3 * i + 2), fflush(stdout);
          ans[3 * i + 2] = gi();
          printf("? %d %d %d\n", bad, good, 3 * i + 3), fflush(stdout);
          ans[3 * i + 3] = gi();
        }
        if (t1 == 1 && t2 == 0) {
          good = 3 * i - 1, bad = 3 * i + 2;
          ans[bad] = 0, ans[good] = 1;
          printf("? %d %d %d\n", bad, good, 3 * i), fflush(stdout);
          ans[3 * i] = gi();
          ans[3 * i + 1] = 1 - ans[3 * i];
          printf("? %d %d %d\n", bad, good, 3 * i - 2), fflush(stdout);
          ans[3 * i - 2] = gi();
          printf("? %d %d %d\n", bad, good, 3 * i + 3), fflush(stdout);
          ans[3 * i + 3] = gi();
        }
        if (t1 == 0 && t2 == 1) {
          good = 3 * i - 2, bad = 3 * i - 1;
          ans[3 * i - 2] = 1, ans[3 * i - 1] = 0, ans[3 * i] = 1,
                      ans[3 * i + 1] = 0, ans[3 * i + 2] = 1,
                      ans[3 * i + 3] = 0;
        }
      }
      for (int j = 1; 3 * j <= n; ++j) {
        if (j == i || j == i + 1) continue;
        if (typ[j] == 0) {
          printf("? %d %d %d\n", good, 3 * j - 2, 3 * j - 1), fflush(stdout);
          int t = gi();
          if (t == 0) {
            ans[3 * j - 2] = ans[3 * j - 1] = 1;
            printf("? %d %d %d\n", bad, good, 3 * j), fflush(stdout);
            ans[3 * j] = gi();
          } else {
            ans[3 * j] = 0;
            printf("? %d %d %d\n", bad, good, 3 * j - 2), fflush(stdout);
            ans[3 * j - 2] = gi();
            ans[3 * j - 1] = 1 - ans[3 * j - 2];
          }
        } else {
          printf("? %d %d %d\n", bad, 3 * j - 2, 3 * j - 1), fflush(stdout);
          int t = gi();
          if (t == 1) {
            ans[3 * j - 2] = ans[3 * j - 1] = 1;
            printf("? %d %d %d\n", bad, good, 3 * j), fflush(stdout);
            ans[3 * j] = gi();
          } else {
            ans[3 * j] = 1;
            printf("? %d %d %d\n", bad, good, 3 * j - 2), fflush(stdout);
            ans[3 * j - 2] = gi();
            ans[3 * j - 1] = 1 - ans[3 * j - 2];
          }
        }
      }
      break;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (ans[i] == 0) cnt++;
  }
  printf("! %d ", cnt);
  for (int i = 1; i <= n; ++i) {
    if (ans[i] == 0) {
      printf("%d ", i);
    }
  }
  puts(""), fflush(stdout);
}
int main() {
  int T = gi();
  while (T--) work();
  return 0;
}
