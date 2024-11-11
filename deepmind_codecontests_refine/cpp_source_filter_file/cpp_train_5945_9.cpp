#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  long long S = a + b;
  long long ats = LLONG_MAX;
  set<long long> oka, okb;
  for (long long i = 1; i * i <= a; i++)
    if (a % i == 0) {
      long long x = i;
      long long y = a / i;
      oka.insert(max(x, y));
    }
  for (long long i = 1; i * i <= b; i++)
    if (b % i == 0) {
      long long x = i;
      long long y = b / i;
      okb.insert(max(x, y));
    }
  for (long long i = 1; i * i <= S; i++)
    if (S % i == 0) {
      long long x = i;
      long long y = S / i;
      auto ita = oka.upper_bound(y);
      if (ita != oka.begin()) {
        ita--;
        long long Y = *ita;
        long long X = a / Y;
        if (Y <= y && X <= x) ats = min(ats, 2 * (x + y));
      }
      auto itb = okb.upper_bound(y);
      if (itb != okb.begin()) {
        itb--;
        long long Y = *itb;
        long long X = a / Y;
        if (Y <= y && X <= x) ats = min(ats, 2 * (x + y));
      }
    }
  cout << ats;
}
