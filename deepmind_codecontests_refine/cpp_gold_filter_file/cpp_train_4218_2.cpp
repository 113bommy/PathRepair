#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  cin >> x >> y;
  if (gcd(x, y) != 1) {
    puts("Impossible");
    return 0;
  }
  vector<pair<long long, char> > ans;
  while (x > 1 || y > 1) {
    if (x > y) {
      ans.push_back(make_pair(x / y, 'A'));
      x %= y;
    } else {
      ans.push_back(make_pair(y / x, 'B'));
      y %= x;
    }
  }
  ans.back().first--;
  for (auto it : ans) cout << it.first << it.second;
  return 0;
}
