#include <bits/stdc++.h>
using namespace std;
template <class TAT>
inline void read(TAT &a) {
  static char cc;
  static bool f;
  while ((cc = getchar()) != '-' && (cc < '0' || cc > '9'))
    ;
  if (cc == '-')
    f = 1, a = 0;
  else
    f = 0, a = cc - 48;
  while ((cc = getchar()) >= '0' && cc <= '9') a = a * 10 + cc - 48;
  if (f) a = -a;
}
template <class TAT>
inline void write(TAT a) {
  static char cc[27];
  static int ct;
  if (a == 0) {
    putchar('0');
    return;
  }
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  ct = 0;
  while (a) cc[++ct] = a % 10 + '0', a /= 10;
  while (ct) putchar(cc[ct--]);
}
void begin() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void end() {
  fclose(stdin);
  fclose(stdout);
}
template <class TAT>
void Ckmax(TAT &a, const TAT &b) {
  if (a < b) a = b;
}
template <class TAT>
void Ckmin(TAT &a, const TAT &b) {
  if (a > b) a = b;
}
const int maxn = 115;
int n;
bool flag[maxn] = {0};
int prime[maxn], pt = 0;
int Hs = 0;
void Solve() {
  char cc[7];
  for (int i = 2; i <= 100; ++i) {
    if (flag[i] == 0) {
      prime[++pt] = i;
      for (int j = 2; j * prime[pt] <= 100; ++j) {
        flag[i * prime[pt]] = 1;
      }
    }
  }
  pt = 20;
  for (int i = 1; i <= pt; ++i) {
    printf("%d\n", prime[i]);
    fflush(stdout);
    scanf("%s", cc);
    if (cc[0] == 'y') {
      for (int j = i; prime[j] * prime[i] <= 100; ++j) {
        printf("%d\n", prime[j] * prime[i]);
        fflush(stdout);
        scanf("%s", cc);
        if (cc[0] == 'y') {
          Hs = 1;
          break;
        }
      }
      break;
    }
  }
  if (Hs) {
    puts("composite");
  } else {
    puts("prime");
  }
  fflush(stdout);
}
int main() {
  Solve();
  return 0;
}
