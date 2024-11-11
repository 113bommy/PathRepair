#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
template <class T>
inline void gmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline void gmin(T &a, T b) {
  if (b < a) a = b;
}
using namespace std;
const int N = 1e5 + 10, M = 2e6 + 10, Z = 1e9 + 7, maxint = 2147483647,
          ms1 = 16843009, ms31 = 522133279, ms63 = 1061109567,
          ms127 = 2139062143;
const double PI = acos(-1.0), eps = 1e-8;
void fre() {
  freopen("/Users/luras/Desktop/in.txt", "r", stdin);
  freopen("/Users/luras/Desktop/out.txt", "w", stdout);
}
const int INF = 1e9;
int casenum, casei;
long long c[210];
int n, a[N], num;
void init() {
  c[4] = 1;
  for (int i = 5; i <= 200; i++) {
    c[i] = c[i - 1] * i / (i - 4);
  }
}
int main() {
  init();
  while (~scanf("%d", &n)) {
    num = 0;
    while (n) {
      for (int i = 200; i >= 4; i--) {
        if (n >= c[i]) {
          n -= c[i];
          a[++num] = i;
        }
      }
    }
    a[num + 1] = 0;
    for (int i = 1; i <= num; i++) {
      printf("a");
      for (int j = 1; j <= a[i] - a[i + 1]; j++) {
        printf("b");
      }
    }
    printf(" abbbb");
    puts("");
  }
  return 0;
}
