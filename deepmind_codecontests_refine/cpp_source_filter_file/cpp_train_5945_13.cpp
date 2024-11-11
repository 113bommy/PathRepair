#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  set<pair<long long, long long>> diva;
  for (long long i = 1; i * i <= a; ++i)
    if (a % i == 0) diva.insert(diva.end(), {i, a / i});
  set<pair<long long, long long>> divb;
  for (long long i = 1; i * i <= b; ++i)
    if (b % i == 0) divb.insert(divb.end(), {i, b / i});
  long long res = a + a + b + b + 2;
  for (long long i = 2; i * i <= (a + b); ++i) {
    if ((a + b) % i == 0) {
      long long h = i;
      long long w = (a + b) / i;
      auto uba = upper_bound(diva.begin(), diva.end(), make_pair(h, w));
      --uba;
      auto ubb = upper_bound(divb.begin(), divb.end(), make_pair(h, w));
      --ubb;
      if (uba->second < w || ubb->second < w) res = min(res, h + h + w + w);
    }
  }
  cout << res;
  return 0;
}
