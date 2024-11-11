#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
long double pi = 3.1415926535897932384626433832795;
long long mod = 1e9 + 7;
const int N = 2e5 + 10;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int m;
int a[N], b[N], ans[N];
multiset<int> aa;
set<pair<int, int> > bb;
int main() {
  cin >> m;
  for (int i = 0; i < m; i++) cin >> a[i], aa.insert(-a[i]);
  for (int i = 0; i < m; i++) cin >> b[i], bb.insert(make_pair(a[i], i));
  for (int i = 0; i < m; i++) {
    pair<int, int> b1 = *bb.begin();
    bb.erase(bb.begin());
    int a1 = *aa.begin();
    aa.erase(aa.find(a1));
    ans[b1.second] = a1;
  }
  for (int i = 0; i < m; i++) cout << -ans[i] << ' ';
  return 0;
}
