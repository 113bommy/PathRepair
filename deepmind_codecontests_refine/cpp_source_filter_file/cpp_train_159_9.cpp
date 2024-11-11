#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long s, t;
vector<long long> price;
vector<long long> tank;
vector<long long> gas;
vector<long long> dist;
vector<long long> sums;
int getfirst(long long tank) {
  int start = -1, end = (int)(price.size()) - 1;
  while (start != end) {
    int mid = (start + end + 1) / 2;
    if (dist[mid] * 2 <= tank)
      start = mid;
    else
      end = mid - 1;
  }
  return start;
}
int main() {
  cin >> n >> k >> s >> t;
  tank.resize(n);
  price.resize(n);
  gas.resize(k);
  for (int i = (0); i < (n); ++i) scanf("%d %d", &price[i], &tank[i]);
  for (int i = (0); i < (k); ++i) scanf("%d", &gas[i]);
  gas.push_back(s);
  gas.push_back(0);
  sort(gas.begin(), gas.end());
  for (int i = (0); i < ((int)(gas.size()) - 1); ++i)
    dist.push_back(gas[i + 1] - gas[i]);
  sort(dist.begin(), dist.end());
  sums.push_back(0);
  for (int i = (0); i < ((int)(dist.size())); ++i)
    sums.push_back(sums.back() + dist[i]);
  long long minprice = 1.5e9;
  for (int i = (0); i < (n); ++i)
    if (dist.back() <= tank[i]) {
      int pos = getfirst(tank[i]);
      long long extra = ((int)(dist.size()) - 1 - pos) * tank[i] -
                        (sums.back() - sums[pos + 1]);
      long long time =
          sums[pos + 1] + (sums.back() - sums[pos + 1]) * 2 - extra;
      if (time <= t) minprice = min(minprice, price[i]);
    }
  if (minprice > 1.1e9)
    cout << -1 << endl;
  else
    cout << minprice << endl;
  return 0;
}
