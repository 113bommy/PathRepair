#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int res = 0;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  while (c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
  return res;
}
const int N = 300000001;
bitset<N> prime;
int main() {
  int l = in(), r = in();
  prime[1] = 1;
  prime[2] = 0;
  for (int i = 3; i * i <= r; i += 2) {
    if (!prime[i]) {
      for (int j = i * i; j <= r; j += i << 1) {
        prime[j] = 1;
      }
    }
  }
  int ans = 0;
  if (l == 2 || r == 2) ans++;
  for (int i = l; i <= r; i++) {
    if (!prime[i] && i % 4 == 1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
