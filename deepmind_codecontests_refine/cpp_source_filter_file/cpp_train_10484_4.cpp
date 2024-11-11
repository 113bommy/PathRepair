#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
double tick() {
  static clock_t oldt;
  clock_t newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin.ignore(0);
  long long a, b, c, n;
  cin >> a >> b >> c >> n;
  if (n > a + b - c && c < a && c < b)
    cout << n - (a + b - c);
  else
    cout << -1;
}
