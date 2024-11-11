#include <bits/stdc++.h>
using namespace std;
const int MAXCOST = 300000;
vector<long long> ncost, pcost;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  long long maxcost = (n + 1) * (1001 - n);
  ncost.resize(maxcost + 1);
  pcost.resize(maxcost + 1);
  vector<long long> plist, nlist;
  for (long long i = 0; i < (k); ++i) {
    long long x;
    cin >> x;
    if (x > n)
      pcost[x - n] = 1;
    else
      ncost[n - x] = 1;
  }
  if (ncost[0] == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 1; i <= 1000; i++) {
    if (pcost[i] == 1) plist.push_back(i);
    if (ncost[i] == 1) nlist.push_back(i);
  }
  for (long long i = 0; i < (1001); ++i) {
    if (pcost[i] == ncost[i] && ncost[i] == 1) {
      cout << 2 << endl;
      return 0;
    }
  }
  for (long long i = 1; i <= maxcost; i++) {
    if (pcost[i] == 0) {
      pcost[i] = MAXCOST;
      for (long long j : plist) {
        if (j > i) continue;
        pcost[i] = min(pcost[i], pcost[i - j] + pcost[j]);
      }
    }
    if (ncost[i] == 0) {
      ncost[i] = MAXCOST;
      for (long long j : nlist) {
        if (j > i) continue;
        ncost[i] = min(ncost[i], ncost[i - j] + ncost[j]);
      }
    }
  }
  long long ans = MAXCOST;
  for (int i = 1; i <= maxcost; i++) {
    ans = min(ans, pcost[i] + ncost[i]);
  }
  cout << ((MAXCOST == ans) ? (-1) : ans) << endl;
}
