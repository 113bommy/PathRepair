#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 5;
int n, m;
struct hash_table {
  unsigned long long seed;
  unsigned long long Hash[N], temp[N];
  void Set(unsigned long long num) { seed = num; }
  void work(char *s, int n) {
    temp[0] = 1;
    Hash[0] = 0;
    for (int i = 1; i <= n; i++) temp[i] = temp[i - 1] * seed;
    for (int i = 1; i <= n; i++) Hash[i] = (Hash[i - 1] * seed + (s[i] - 'a'));
  }
  unsigned long long get(int l, int r) {
    return Hash[r] - Hash[l - 1] * temp[r - l + 1];
  }
} h;
unsigned long long g1[N], g2[N][N];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    h.Set(2);
    for (int i = 1; i <= n; i++) {
      char s[N];
      scanf("%s", s + 1);
      h.work(s, m);
      g1[i] = h.get(1, m);
    }
    for (int i = 1; i <= m; i++) {
      char s[N];
      scanf("%s", s + 1);
      h.work(s, n);
      for (int j = 1; j <= n - m + 1; j++) g2[i][j] = h.get(j, j + m - 1);
    }
    int ansi = -1, ansj = -1;
    for (int i = 1; i <= n - m + 1; i++) {
      for (int j = 1; j <= n - m + 1; j++) {
        bool OK = 1;
        for (int k = 1; k <= m; k++)
          if (g2[k][j] != g1[i + k - 1]) {
            OK = 0;
            break;
          }
        if (OK) {
          ansi = i, ansj = j;
          break;
        }
      }
    }
    printf("%d %d\n", ansi, ansj);
  }
  return 0;
}
