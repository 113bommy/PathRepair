#include <bits/stdc++.h>
using namespace std;
int n, a[26];
char pal[111111];
inline bool is_pal(int k, int can) {
  vector<int> odd(0);
  for (int i = 0; i < n; ++i) {
    if (a[i] % k) return 0;
    if (a[i] % (2 * k)) odd.push_back(i);
  }
  if ((int)(odd).size() > 1) return 0;
  if ((int)(odd).size() == 1 && !can) return 0;
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < a[i] / (2 * k); ++j) {
      pal[pos++] = 'a' + i;
    }
  }
  if ((int)(odd).size()) pal[pos++] = 'a' + odd[0];
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < a[i] / (2 * k); ++j) {
      pal[pos++] = 'a' + i;
    }
  }
  pal[pos] = 0;
  return 1;
}
inline void die(int ans, int reps, char middle) {
  printf("%d\n", ans);
  for (int i = 0; i < reps; ++i) {
    printf("%s", pal);
    if (middle != '!') printf("%c", middle);
  }
  printf("\n");
  exit(0);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int ans = 4; ans > 1; --ans) {
    if (ans % 2 == 1) {
      for (int let = 0; let < n; ++let) {
        if (a[let] >= ans) {
          a[let] -= ans;
          if (is_pal(ans, 0)) {
            die(ans, ans, 'a' + let);
          }
          a[let] += ans;
        }
      }
    } else {
      for (int let = 0; let < n; ++let) {
        if (is_pal(ans / 2, 0)) {
          die(ans, ans / 2, '!');
        }
      }
    }
  }
  if (is_pal(1, 1)) {
    die(1, 1, '!');
  }
  printf("0\n");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < a[i]; ++j) {
      printf("%c", 'a' + i);
    }
  }
  printf("\n");
}
