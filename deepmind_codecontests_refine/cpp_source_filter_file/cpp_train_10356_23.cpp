#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
vector<long long> sqn;
multiset<pair<long long, long long> > rat;
int main() {
  istream &fin = cin;
  FILE *fpin = stdin;
  int n, m;
  fin >> n >> m;
  sqn.clear();
  for (long long i = 0; i <= 5000; i++) {
    sqn.push_back(i * i);
  }
  long long res = 0;
  for (long long b = 1; b <= n; b++) {
    long long maxrt = b * b - 1;
    long long minrt = max(0LL, b * b - min(b * b, (long long)m));
    long long maxi =
        upper_bound(sqn.begin(), sqn.end(), maxrt) - sqn.begin() - 1;
    long long mini = lower_bound(sqn.begin(), sqn.end(), minrt) - sqn.begin();
    if (mini != (int)sqn.size()) {
      res += (maxrt + 1 - minrt) * 2;
      if (maxi >= mini) {
        res -= (maxi + 1 - mini) * 2;
        multiset<pair<long long, long long> >::iterator spi =
            rat.insert(make_pair(-b - maxi, -b - mini));
        for (int s = 0; s < 2; s++) {
          if (spi != rat.begin()) {
            multiset<pair<long long, long long> >::iterator tspi = spi;
            tspi--;
            if (tspi->second >= spi->first) {
              pair<long long, long long> pll(tspi->first, spi->second);
              rat.erase(tspi);
              rat.erase(spi);
              spi = rat.insert(pll);
            }
          }
          if (spi != rat.end()) {
            multiset<pair<long long, long long> >::iterator tspi = spi;
            tspi++;
            if (tspi != rat.end()) {
              if (spi->second >= tspi->first) {
                pair<long long, long long> pll(spi->first, tspi->second);
                rat.erase(tspi);
                rat.erase(spi);
                spi = rat.insert(pll);
              }
            }
          }
          if (s == 0) spi = rat.insert(make_pair(-b + mini, -b + maxi));
        }
      }
    }
  }
  for (multiset<pair<long long, long long> >::iterator spi = rat.begin();
       spi != rat.end(); spi++) {
    res += spi->second + 1 - spi->first;
  }
  cout << res << endl;
}
