#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& cout, vector<T> V) {
  cout << "[ ";
  for (auto v : V) cout << v << ' ';
  return cout << ']';
}
template <class L, class R>
ostream& operator<<(ostream& cout, pair<L, R> P) {
  return cout << '(' << P.first << ',' << P.second << ')';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  cin >> a;
  reverse(a.begin(), a.end());
  long long int n = a.size();
  vector<long long int> b;
  for (long long int i = 0; i < (n); i++)
    if (a[i] == 'M') b.push_back(i);
  if (!b.size()) {
    cout << 0 << '\n';
    return 0;
  }
  long long int pt = b[0], t;
  long long int g = b[0];
  for (long long int i = 1; i < b.size(); i++) {
    g += b[i] - b[i - 1] - 1;
    if (pt > b[i] - b[i - 1] - 1) {
      t = max(g, pt + 1);
    } else {
      t = g;
    }
    pt = t;
  }
  cout << t << '\n';
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  ;
}
