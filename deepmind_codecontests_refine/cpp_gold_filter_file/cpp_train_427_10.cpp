#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e9;
const long long infll = 1e18;
double eps = 0.0000001;
ifstream in("input.txt");
ofstream out("output.txt");
;
long long n;
vector<long long> c;
vector<long long> t;
void init() {
  cin >> n;
  c.resize(n);
  t.resize(n);
  for (long long i = 0; i < n; i++) cin >> c[i];
  for (long long i = 0; i < n; i++) cin >> t[i];
}
void solve() {
  multiset<long long> razn1, razn2;
  for (long long i = 0; i < n - 1; i++) {
    razn1.insert(c[i + 1] - c[i]);
    razn2.insert(t[i + 1] - t[i]);
  }
  if (razn1 == razn2 && c[0] == t[0] && c[n - 1] == t[n - 1])
    cout << "Yes";
  else
    cout << "No";
}
signed main() {
  init();
  solve();
  return 0;
}
