#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
const int MIN = 2e5 + 20;
const int MAX = 1e9 + 20;
str s;
map<char, ll> m;
ll b, a[MIN], c, k, l, i, n, d, j;
int pro(str x) {
  k = 0;
  for (auto to : x) k += m[to];
  return k;
}
int main() {
  m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = m['y'] = 1;
  cin >> n;
  for (i = (1); i <= (n); i++) cin >> a[i];
  getline(cin, s);
  l = 1;
  while (getline(cin, s)) {
    if (pro(s) != a[l]) {
      cout << "NO";
      return 0;
    }
    l++;
  }
  cout << "YES";
}
