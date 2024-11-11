#include <bits/stdc++.h>
using namespace std;
const int maxn = 6002 * 3000;
int prime[maxn], flag[maxn], a[maxn / 3000], cnt = 0;
void get_prime() {
  for (int i = 2; i < maxn; i++) {
    if (!flag[i]) {
      prime[cnt++] = i;
    }
    for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
      flag[prime[j] * i] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
void goldbach(int s) {
  for (int i = 2; i * i <= s; i++) {
    if (!flag[i] && !flag[s - i]) {
      a[i] = 2;
      return;
    }
  }
}
int main() {
  int n, s;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) a[i] = 1;
  s = (n * (n + 1)) >> 1;
  get_prime();
  if (flag[s]) {
    if (s % 2 == 0) {
      goldbach(s);
    } else if (flag[s - 2]) {
      a[2] = 2;
    } else {
      a[3] = 3;
      goldbach(s - 3);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d%s", a[i], i == n ? "\n" : " ");
  return 0;
}
