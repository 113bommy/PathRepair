#include <bits/stdc++.h>
using namespace std;
char ch[1010000];
long long x[1010000];
long long g[10];
vector<long long> vt, ans;
signed main() {
  long long T, n, m, cnt, num, k;
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld", &n);
    long long mmax = 0;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &x[i]);
      g[x[i] % 3]++;
      mmax = max(x[i], mmax);
    }
    if (mmax == 1) {
      printf("1\n");
      continue;
    } else if (mmax == 2) {
      long long flag = 0;
      for (long long i = 1; i <= n; i++) {
        if (x[i] == 1) {
          flag = 1;
        }
      }
      if (flag) {
        printf("2\n");
      } else {
        printf("1\n");
      }
      continue;
    } else if (mmax == 3) {
      long long flag = 0;
      for (long long i = 1; i <= n; i++) {
        if (x[i] != 3) {
          flag = 1;
        }
      }
      if (flag) {
        printf("2\n");
      } else {
        printf("1\n");
      }
      continue;
    }
    long long t = mmax % 3;
    long long cnt = (mmax + 2) / 3;
    if (t == 0) {
      long long flag = 0;
      for (long long i = 1; i <= n; i++) {
        if (x[i] % 3 != 0) {
          flag = 1;
          break;
        }
      }
      if (flag) {
        cnt++;
      }
    } else if (t == 1) {
      long long flag = 0;
      for (long long i = 1; i <= n; i++) {
        if (x[i] % 3 == 2) {
          flag = 1;
          break;
        }
      }
      if (flag) {
        for (long long i = 1; i <= n; i++) {
          if (x[i] == 1 || x[i] == mmax - 1) {
            flag = 0;
            break;
          }
        }
        if (flag == 0) {
          cnt++;
        }
      }
    } else if (t == 2) {
      long long flag = 0;
      for (long long i = 1; i <= n; i++) {
        if (x[i] % 3 != 2) {
          flag = 1;
          break;
        }
      }
      if (flag) {
        cnt++;
      }
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
