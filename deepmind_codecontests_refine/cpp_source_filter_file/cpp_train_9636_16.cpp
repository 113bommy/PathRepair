#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
const long long LIMIT = 1e5;
long long l[MAX], t[MAX], s[MAX], e[MAX];
long long n, r;
void die() {
  puts("-1");
  exit(0);
}
int main() {
  scanf("%lld %lld", &n, &r);
  for (int i = int(1); i < int(n + 1); i++) {
    scanf("%lld", l + i);
  }
  for (int i = int(1); i < int(n + 1); i++) {
    scanf("%lld", t + i);
    if (l[i] > t[i]) {
      die();
    }
  }
  s[1] = 1, e[1] = l[1];
  for (int i = int(2); i < int(n + 1); i++) {
    s[i] = e[i - 1] + 1;
    e[i] = s[i] + l[i];
  }
  vector<long long> places;
  long long cur_limit = 0;
  long long ans = 0;
  for (int i = int(1); i < int(n + 1); i++) {
    if (2 * l[i] <= t[i]) {
      continue;
    }
    long long di = 2 * l[i] - t[i];
    long long hi = max<long long>(0, cur_limit - s[i] + 1);
    long long ni = max<long long>(0, di - hi);
    if (ni == 0) {
      continue;
    }
    long long dn = (ni + r - 1) / r;
    if (ans + dn <= LIMIT) {
      long long p = e[i] - ni + 1;
      long long cur_time =
          ans * r + max<long long>(0, ((p - 1) - ans * r) * 2LL);
      for (int j = int(0); j < int(dn); j++) {
        places.push_back(cur_time);
        cur_time += r;
      }
    }
    ans += dn;
    long long last = (e[i] - ni + 1) + r * dn - 1;
    cur_limit = last;
  }
  printf("%lld\n", ans);
  if (ans <= LIMIT) {
    for (auto &each : places) {
      printf("%lld ", each);
    }
    printf("\n");
  }
  return 0;
}
