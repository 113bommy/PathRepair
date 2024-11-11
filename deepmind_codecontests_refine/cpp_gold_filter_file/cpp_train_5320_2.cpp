#include <bits/stdc++.h>
using namespace std;
int n, cnt, mmax;
int prime[20000008], A[300008], flag[20000008];
bool vis[20000008];
inline int read() {
  int x = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return w ? -x : x;
}
void biao() {
  vis[0] = vis[1] = true;
  for (int i = 2; i <= mmax; i++) {
    if (!vis[i]) prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= mmax; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
  return;
}
inline int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  n = read();
  int g = 0;
  bool q1 = true;
  bool q2 = true;
  mmax = -1;
  for (int i = 1; i <= n; i++) {
    A[i] = read();
    mmax = max(mmax, A[i]);
    if (A[i] != 1 || vis[A[i]]) q1 = false;
    if (i != 1)
      if (A[i - 1] != A[i]) q2 = false;
  }
  if (q2)
    printf("-1\n");
  else if (q1)
    printf("%d\n", n - 1);
  else {
    biao();
    for (int i = 1; i <= n; i++) {
      if (i == 1)
        g = A[i];
      else
        g = gcd(A[i], g);
    }
    mmax = -1;
    for (int i = 1; i <= n; i++) {
      A[i] /= g;
      for (int j = 1; j <= cnt && prime[j] * prime[j] <= A[i]; j++) {
        if (A[i] % prime[j] == 0) {
          flag[prime[j]]++;
          mmax = max(mmax, prime[j]);
          while (A[i] % prime[j] == 0) A[i] /= prime[j];
        }
      }
      if (A[i] != 1) flag[A[i]]++, mmax = max(mmax, A[i]);
    }
    printf("%d\n", n - *max_element(flag + 1, flag + mmax + 1));
  }
}
