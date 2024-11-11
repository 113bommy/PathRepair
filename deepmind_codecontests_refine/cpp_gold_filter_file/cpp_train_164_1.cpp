#include <bits/stdc++.h>
using namespace std;
pair<int, int> a, b, c;
long long dist(pair<int, int> a, pair<int, int> b) {
  return 1LL * (a.first - b.first) * (a.first - b.first) +
         1LL * (a.second - b.second) * (a.second - b.second);
}
long long area(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return 1LL * a.first * b.second + 1LL * a.second * c.first +
         1LL * b.first * c.second - 1LL * b.second * c.first -
         1LL * a.second * b.first - 1LL * a.first * c.second;
}
int main() {
  cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
  if (dist(a, b) == dist(b, c) && area(a, b, c) != 0)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
