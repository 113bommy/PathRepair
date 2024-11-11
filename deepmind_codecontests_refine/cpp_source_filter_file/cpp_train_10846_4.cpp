#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 50;
const int inf = 1e9;
long long b[maxn];
int two_pow[maxn];
int cnt[100];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", b + i);
    long long tmp = b[i];
    while (tmp % 2 == 0) {
      tmp /= 2;
      two_pow[i]++;
    }
    cnt[two_pow[i]]++;
  }
  int maxans = 0;
  int p = 0;
  for (int i = 0; i < 100; ++i)
    if (maxans < cnt[i]) {
      maxans = cnt[i];
      p = i;
    }
  printf("%d\n", n - maxans);
  for (int i = 0; i < n; ++i) {
    if (two_pow[i] != p) printf("%d\n", b[i]);
  }
  return 0;
}
