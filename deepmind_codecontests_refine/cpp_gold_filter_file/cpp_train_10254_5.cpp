#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const ll INF = 1e18 + 1;
string convert(string cur) {
  if (cur.size() % 2 == 1) return cur;
  string left = convert(cur.substr(0, cur.size() / 2));
  string right = convert(cur.substr(cur.size() / 2));
  if (left > right)
    return right + left;
  else
    return left + right;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  if (convert(a) == convert(b))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
