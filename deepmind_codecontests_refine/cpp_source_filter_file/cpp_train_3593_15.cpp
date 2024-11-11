#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5, MAXLOG = 18;
const long long MOD = 1e9 + 7;
int cnt[200];
void solve() {
  int n, i, j, k, l, cnt_odd = 0, len = 0;
  cin >> n;
  for ((i) = (int)(0); (i) < (int)(n); (i)++) {
    cin >> cnt[i];
    len += cnt[i];
    cnt_odd += cnt[i] % 2;
  }
  if (cnt_odd > 1) {
    printf("0\n");
    for ((i) = (int)(0); (i) < (int)(n); (i)++) {
      for ((j) = (int)(0); (j) < (int)(cnt[i]); (j)++) {
        putchar(i + 'a');
      }
    }
    putchar('\n');
    return;
  }
  if (cnt_odd == 0) {
    for (i = len;; i--) {
      if (i % 2 == 0 && len % i == 0) {
        int fl = 0;
        for ((j) = (int)(0); (j) < (int)(n); (j)++) {
          if (cnt[j] % i) {
            fl = 1;
            break;
          }
        }
        if (!fl) {
          printf("%d\n", i);
          for (j = 0; j < i / 2; j++) {
            for (k = 0; k < n; k++) {
              for (l = 0; l < cnt[k] / i; l++) {
                putchar(k + 'a');
              }
            }
            for (k = n - 1; k >= 0; k--) {
              for (l = 0; l < cnt[k] / i; l++) {
                putchar(k + 'a');
              }
            }
          }
          putchar('\n');
          return;
        }
      }
    }
  }
  int ind = 0;
  for ((ind) = (int)(0); (ind) < (int)(n); (ind)++) {
    if (cnt[ind] % 2) {
      break;
    }
  }
  for (i = len;; i--) {
    if (i % 2 == 0 && len % (i / 2) == 0) {
      int fl = 0;
      for ((j) = (int)(0); (j) < (int)(n); (j)++) {
        if (j != ind && cnt[j] % i) {
          fl = 1;
          break;
        }
        if (j == ind && (cnt[j] - (i / 2)) % i) {
          fl = 1;
          break;
        }
      }
      if (!fl) {
        printf("%d\n", i / 2);
        for (j = 0; j < i / 2; j++) {
          for (k = 0; k < n; k++) {
            for (l = 0; l < cnt[k] / i; l++) {
              putchar(k + 'a');
            }
          }
          putchar(ind + 'a');
          for (k = n - 1; k >= 0; k--) {
            for (l = 0; l < cnt[k] / i; l++) {
              putchar(k + 'a');
            }
          }
        }
        putchar('\n');
        return;
      }
    }
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
