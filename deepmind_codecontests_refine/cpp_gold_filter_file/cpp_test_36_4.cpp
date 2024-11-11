#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205;
const int MAXP = 20005;
int t, n, cnt, sum;
bool f;
int a[MAXN];
int prime[MAXP];
int isPrime[MAXP];
inline int read() {
  int x = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c <= '9' && c >= '0') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
void doGetPrime() {
  prime[++cnt] = 2;
  isPrime[2] = 1;
  for (int i = 3; i <= MAXP; i++) {
    f = true;
    for (int j = 1; j <= cnt; j++) {
      if (i % prime[j] == 0) {
        f = false;
        break;
      }
    }
    if (f) {
      prime[++cnt] = i;
      isPrime[i] = 1;
    }
  }
}
int main(void) {
  doGetPrime();
  t = read();
  for (int T = 1; T <= t; T++) {
    n = read();
    sum = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      sum += a[i];
    }
    if (!isPrime[sum]) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
    } else {
      for (int i = 1; i <= n; i++) {
        if (!isPrime[sum - a[i]]) {
          cout << n - 1 << endl;
          for (int j = 1; j <= n; j++)
            if (i - j) cout << j << " ";
          cout << endl;
          break;
        }
      }
    }
  }
  return 0;
}
