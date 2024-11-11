#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  ll mn = min({a, b, c, d, e});
  cout << (n + mn - 1) / mn + 4 << endl;
}
