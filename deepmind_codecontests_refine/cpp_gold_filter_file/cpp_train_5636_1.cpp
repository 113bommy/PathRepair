#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline string get() {
  char ch[1000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 60;
const long long maxn = 2e6 + 100;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 100;
long long cnt[maxn], f[maxn];
long long res;
int32_t main() {
  long long n = in();
  for (long long i = 1; i <= n + 500; i++) f[i] = (i % 9 == 0 ? 9 : i % 9);
  for (long long i = 1; i <= n; i++) cnt[f[i]]++;
  for (long long i = 1; i < 10; i++) {
    for (long long j = 1; j < 10; j++) {
      for (long long num = 1; num <= n; num++) {
        if (f[i * j] == f[num]) res += cnt[i] * cnt[j];
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = i; j <= n; j += i) {
      if (f[f[i] * f[j / i]] == f[j]) res--;
    }
  }
  cout << res << "\n";
}
