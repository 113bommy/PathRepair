#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<ld>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
str tout[4] = {"No", "Yes", "NO", "YES"};
const ll M18 = 1e18;
const int M9 = 1e9;
const int N = 1e5;
int main() {
  int n, a = 0;
  vi v;
  str s;
  cin >> n >> s;
  for (int i = (0); i < (int((s).size())); i++) {
    if (s[i] == 'B')
      a++;
    else {
      if (a > 0) v.push_back(a);
      a = 0;
    }
  }
  if (a > 0) v.push_back(a);
  cout << int((v).size()) << "\n";
  for (auto& x : v) cout << x << " ";
  return 0;
}
