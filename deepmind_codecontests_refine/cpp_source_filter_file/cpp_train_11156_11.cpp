#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int n, kans, a[1000001];
set<pair<int, int> > ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  kans = n;
  for (int i = 1; i < n; i++) {
    ans.insert(make_pair(i, i + 1));
  }
  ans.insert(make_pair(n, 1));
  for (int i = 1; i < 10001; i++) {
    if (a[i] == 0) {
      for (int j = (2 * i + 1) * (2 * i + 1); j < 20001; j += 2 * i + 1) {
        if (j % 2 == 1) a[(j - 1) >> 1] = 1;
      }
    }
  }
  int i = 1;
  while (a[(kans - 1) >> 1] == 1 || kans % 2 == 0) {
    ans.insert(make_pair(i, (n >> 1) + i));
    kans++;
  }
  cout << kans << endl;
  for (auto it = ans.begin(); it != ans.end(); it++) {
    cout << it->first << ' ' << it->second << endl;
  }
  return 0;
}
