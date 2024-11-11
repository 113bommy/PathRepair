#include <bits/stdc++.h>
using namespace std;
int findMinK(int n, int si) {
  int ki = ceil((long double)n / si);
  if ((ki * si - n) <= ki && (ki * si - n) >= 0) return ki;
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t, n, u;
  cin >> t;
  while (t--) {
    map<int, int> count;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> u;
      if (count.find(u) == count.end())
        count[u] = 1;
      else
        count[u]++;
    }
    int minCnt = 1000001, m = 1000001, tempCnt, res;
    for (auto it = count.begin(); it != count.end(); it++)
      minCnt = min(minCnt, it->second);
    for (int si = 1; si <= minCnt + 1; si++) {
      tempCnt = 0;
      res = 0;
      for (auto it = count.begin(); it != count.end(); it++) {
        int ci = it->second;
        res = findMinK(ci, si);
        if (res == -1) break;
        tempCnt += res;
      }
      if (res != -1) m = min(m, tempCnt);
    }
    cout << m << endl;
  }
  return 0;
}
