#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 5;
ifstream in("date.in");
ofstream out("date.out");
multiset<long long> p;
vector<long long> v[NR];
long long t, cnt, cnt2, n, already, sol;
int main() {
  long long x, y, i, j;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; ++i) {
      cin >> x >> y;
      v[x].push_back(y);
    }
    already = n;
    cnt = 0;
    sol = 0;
    for (i = n - 1; i >= 0; --i) {
      already -= v[i].size();
      for (j = 0; j < v[i].size(); ++j) {
        p.insert(v[i][j]);
      }
      cnt2 = 0;
      for (j = 1; j < i - already - cnt; ++j) {
        sol += *p.begin();
        p.erase(p.begin());
        cnt2++;
      }
      cnt = cnt2;
    }
    cout << sol << '\n';
    p.clear();
    for (i = 0; i <= n; ++i) v[i].clear();
  }
}
