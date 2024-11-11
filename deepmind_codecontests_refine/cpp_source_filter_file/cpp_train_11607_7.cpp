#include <bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using dd = double;
using ldd = long double;
using si = short int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void chech(int a, int b, int c, int d) {
  int delta = c - a;
  if (delta <= 0) return;
  if (c - max(0, b - delta) <= delta) {
    cout << "Polycarp";
    exit(0);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  chech(a, b, c, d);
  chech(b, a, d, c);
  cout << "Vasiliy";
  return 0;
}
