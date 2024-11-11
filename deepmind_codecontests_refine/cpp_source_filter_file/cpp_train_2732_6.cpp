#include <bits/stdc++.h>
using namespace std;
bool notprime[1010];
int pw[60];
vector<int> sp;
long long X;
void init() {
  for (int i = 2; i <= 1000; i++) {
    if (notprime[i]) continue;
    for (int j = i * i; j <= 1000; j += i) notprime[j] = true;
  }
  for (int i = 2; i <= 37; i++)
    if (!notprime[i]) sp.push_back(i);
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long query(long long q) {
  printf("? %lld\n", q);
  fflush(stdout);
  long long ret;
  scanf("%lld", &ret);
  return ret;
}
int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < sp.size(); i++) pw[i] = 0;
    for (int i = 0; i < 6; i++) {
      long long p1 = sp[2 * i], p2 = sp[2 * i + 1];
      long long t1 = 1, t2 = 1;
      while (1) {
        if (t1 * p1 > 1e9) break;
        t1 *= p1;
      }
      while (1) {
        if (t2 * p2 > 1e9) break;
        t2 *= p2;
      }
      long long z = query(t1 * t2);
      while (z % p1 == 0) {
        pw[2 * i]++;
        z /= p1;
      }
      while (z % p2 == 0) {
        pw[2 * i + 1]++;
        z /= p2;
      }
    }
    int cnt = 0;
    int s = 41;
    long long t = 1;
    for (int i = 41; i <= 613; i++) {
      if (notprime[i]) continue;
      if (1e18 / t < i) {
        long long z = query(t);
        for (int j = s; j < i; j++) {
          if (notprime[j]) continue;
          if (z % j == 0) cnt++;
        }
        t = 1;
        s = i;
      }
      t *= i;
    }
    if (t > 1) {
      long long z = query(t);
      for (int j = s; j <= 613; j++) {
        if (notprime[j]) continue;
        if (z % j == 0) cnt++;
      }
    }
    long long ans = 1;
    for (int i = 0; i < sp.size(); i++) ans *= (pw[i] + 1);
    ans *= (1 << cnt);
    if (ans < 8)
      printf("! 8\n");
    else
      printf("! %d\n", ans * 2);
    fflush(stdout);
  }
  return 0;
}
