#include <bits/stdc++.h>
using namespace std;
long long N;
long long qb[100005];
long long lower = 0ll, upper = 1000000000000001ll;
int main() {
  cin >> N;
  for (int i = 0; i < 100005; i++) {
    qb[i] = (long long)(i + 2) * (long long)(i + 2) * (long long)(i + 2);
  }
  while (upper - lower > 1ll) {
    long long mid = (lower + upper) / 2ll;
    long long noways = 0ll;
    for (int i = 0; i < 100005; i++) {
      noways += mid / qb[i];
    }
    if (noways >= N) {
      upper = mid;
    } else {
      lower = mid;
    }
  }
  long long lownum = 0ll, upnum = 0ll;
  for (int i = 0; i < 100005; i++) {
    lownum += lower / qb[i];
    upnum += upper / qb[i];
  }
  if (lownum == N) {
    cout << lower << '\n';
    return 0;
  } else if (upnum == N) {
    cout << upper << '\n';
    return 0;
  }
  cout << "-1\n";
  return 0;
}
