#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
long long n, m, k;
long long a[maxn][15], c[1000005];
int ans, tmp[15], cnt;
int flag;
char s[maxn];
bool ok[maxn];
template <typename T>
inline void read(T &X) {
  X = 0;
  int w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  if (w) X = -X;
}
int cal(int x) {
  int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
int main() {
  memset(a, -1, sizeof(a));
  c[0] = 0;
  for (int i = (1); i <= (80009); i++) {
    c[i] = c[i - 1] + cal(i);
    for (int k = i; i - k <= 9; k--) {
      if (k == 0 && c[i] >= 1 && c[i] <= 150) {
        if (a[c[i]][i - k] < 0) {
          a[c[i]][i - k] = k;
          tmp[i - k]++;
        }
      } else if (k >= 1 && c[i] - c[k - 1] >= 1 && c[i] - c[k - 1] <= 150) {
        if (a[c[i] - c[k - 1]][i - k] < 0) {
          a[c[i] - c[k - 1]][i - k] = k;
          tmp[i - k]++;
        }
      }
    }
  }
  int T, cas = 1;
  read(T);
  while (T--) {
    read(n);
    read(k);
    if (k >= 3) {
      printf("%lld\n", a[n][k]);
    } else if (k == 0) {
      if (n <= 10) {
        printf("%lld\n", a[n][k]);
      } else {
        long long x = n;
        long long cnt = x / 9;
        if (x % 9) printf("%d", x % 9);
        while (cnt--) printf("9");
        puts("");
      }
    } else if (k == 1) {
      if (n <= 35) {
        printf("%lld\n", a[n][k]);
      } else {
        long long x = n;
        long long tmp = x - 26;
        long long cnt = (x - 26) / 9;
        if (cnt & 1) cnt--;
        x = x - 26 - cnt * 9;
        cnt /= 2;
        if (x >= 0 && x % 2 == 0 && x <= 18) {
          if (x) printf("%d", x / 2);
          while (cnt--) printf("9");
          puts("89");
        } else {
          x = n;
          tmp = x - 35;
          cnt = (x - 35) / 9;
          if (cnt & 1) cnt--;
          x = x - 35 - cnt * 9;
          cnt /= 2;
          if (x >= 0 && x % 2 == 0 && x <= 18) {
            if (x) printf("%d", x / 2);
            while (cnt--) printf("9");
            puts("98");
          } else
            puts("-1");
        }
      }
    } else {
      if (n <= 51) {
        printf("%lld\n", a[n][k]);
        continue;
      }
      long long x = n;
      long long tmp = x - 24;
      long long cnt = (x - 24) / 9;
      while (cnt % 3) cnt--;
      x = x - 24 - cnt * 9;
      cnt /= 3;
      if (x >= 0 && x % 3 == 0 && x <= 27) {
        if (x) printf("%d", x / 3);
        while (cnt--) printf("9");
        puts("7");
      } else
        puts("-1");
    }
  }
  return 0;
}
