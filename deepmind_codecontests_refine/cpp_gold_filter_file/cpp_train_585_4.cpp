#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
int main() {
  long long k, d, t;
  cin >> k >> d >> t;
  long long x = (k + d - 1) / d;
  long long per = x * d;
  long long cook2 = 2 * k + (per - k);
  long long ans = 0;
  long long t2 = t * 2;
  long long ans2 = 2ll * (t2 / cook2) * per;
  t2 %= cook2;
  if (2 * k > t2)
    ans2 += t2;
  else {
    t2 -= 2 * k;
    ans2 += 2 * k;
    ans2 += 2 * t2;
  }
  printf("%lld", ans2 / 2);
  if (ans2 % 2 == 1) printf(".5");
}
