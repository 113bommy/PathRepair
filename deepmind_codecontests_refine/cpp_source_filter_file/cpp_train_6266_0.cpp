#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  set<ll> anss;
  anss.insert(4);
  anss.insert(5);
  ll d = -1;
  for (int _ = 0; _ < 30; _++) {
    ll largest = *anss.rbegin();
    anss.insert(2 * largest);
    anss.insert(2 * largest + d);
    d *= -1;
  }
  int n;
  cin >> n;
  if ((anss.find(n) != anss.end()))
    cout << "1\n";
  else
    cout << "0\n";
}
