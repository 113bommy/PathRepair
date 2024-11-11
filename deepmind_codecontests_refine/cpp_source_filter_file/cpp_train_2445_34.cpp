#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A, B, n;
  cin >> A >> B >> n;
  while (n--) {
    long long l, t, m;
    scanf("%lld %lld %lld", &l, &t, &m);
    long long low = A + (l - 1) * B;
    long long id = (t - A) / B;
    id++;
    long long high = A + (id - 1) * B;
    if (t < low) {
      puts("-1");
      continue;
    }
    if (t == low) {
      printf("%lld\n", l);
      continue;
    }
    long long total = m * t;
    long long lll = l, hhh = id;
    long long ans = l;
    long long leftsum = 0;
    if (l > 1) {
      leftsum = 2 * A + (l - 1) * B;
      leftsum *= l;
      leftsum /= 2;
    }
    while (lll < hhh) {
      long long mid = lll + hhh >> 1;
      long long sum = 2 * A + (mid - 1) * B;
      sum *= mid;
      sum /= 2;
      sum -= leftsum;
      if (lll == hhh) {
        if (sum <= total) ans = mid;
        break;
      }
      if (sum == total) {
        ans = mid;
        break;
      }
      if (sum < total) {
        ans = mid;
        lll = mid + 1;
      } else {
        hhh = mid;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
