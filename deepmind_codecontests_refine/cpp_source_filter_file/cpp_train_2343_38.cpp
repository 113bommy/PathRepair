#include <bits/stdc++.h>
using namespace std;
long long num[1000010], cnt[1000010];
void qq(long long *cur) {
  long long i;
  for (i = 0; i <= 1000000; i++) {
    if (cnt[i] & 1) {
      (*cur)++;
      cnt[i + 1] += (cnt[i] / 2);
    } else {
      cnt[i + 1] += (cnt[i] / 2);
    }
  }
  return;
}
int main() {
  long long n;
  long long i;
  while (cin >> n) {
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < n; i++) {
      scanf("%lld", &num[i]);
      cnt[num[i]]++;
    }
    long long cur = 0;
    qq(&cur);
    printf("%lld\n", cur);
  }
  return 0;
}
