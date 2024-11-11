#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int one = k * l;
  int two = one / nl;
  int three = c * d;
  int four = p / np;
  int five = min(min(two, three), four) / n;
  cout << five;
}
