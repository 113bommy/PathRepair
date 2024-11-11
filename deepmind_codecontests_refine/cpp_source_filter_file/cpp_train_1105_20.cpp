#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const int N = 100000;
int main() {
  set<pair<int, int> > se[N + 1];
  for (int w = 2;; ++w) {
    int sum = w * (w + 1) / 2;
    if (sum > N) break;
    for (int i = 1; sum <= N; ++i) {
      se[sum].insert(pair<int, int>(i, w));
      sum += w;
    }
  }
  int grundy[N + 1];
  grundy[0] = 0;
  for (int i = 0; i < (int)N; ++i) {
    set<int> s;
    for (__typeof((se[i]).begin()) it = (se[i]).begin(); it != (se[i]).end();
         ++it) {
      int tmp = 0;
      for (int i = it->first; i < it->first + it->second; ++i) {
        tmp ^= grundy[i];
      }
      s.insert(tmp);
    }
    int g = 0;
    while (s.count(g)) g++;
    grundy[i] = g;
  }
  int n;
  cin >> n;
  if (grundy[n] == 0)
    cout << -1 << endl;
  else {
    int res = INF;
    for (__typeof((se[n]).begin()) it = (se[n]).begin(); it != (se[n]).end();
         ++it) {
      int tmp = 0;
      for (int i = it->first; i < it->first + it->second; ++i) {
        tmp ^= grundy[i];
      }
      if (tmp == 0) {
        res = (res, it->second);
      }
    }
    cout << res << endl;
  }
}
