#include <bits/stdc++.h>
using namespace std;
long long n, m, v;
vector<pair<long long, long long> > a;
long long f(long long x) {
  if (x == 1) return v;
  if (x == v) return 1;
  return x;
}
int main() {
  cin >> n >> m >> v;
  long long max_edge = (((n - 1) * (n - 2)) / 2) + 1;
  if ((max_edge < m) || (n - 1 > m))
    cout << "-1" << endl;
  else {
    bool flag = 1;
    a.push_back(make_pair(1, n));
    for (long long i = 1; (i < n - 1) && flag; i++) {
      for (long long j = i + 1; (j <= n - 1) && flag; j++) {
        a.push_back(make_pair(i, j));
        if (a.size() == m) flag = 0;
      }
    }
    for (long long i = 0; i < a.size(); i++) {
      cout << f(a[i].first) << " " << f(a[i].second) << endl;
    }
  }
}
