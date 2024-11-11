#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * 1e5 + 9;
const int MOD = 1e9 + 7;
const double epsilon = 1e-8;
bool equal(double a, double b) {
  a = b - a;
  return fabs(a) <= epsilon;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first > b.first;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int odd = 0, even = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x % 2)
      odd++;
    else
      even++;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x % 2 && even > 0) {
      res++;
      even--;
    }
    if (x % 2 == 0 && odd > 0) {
      res++;
      odd--;
    }
  }
  cout << res << endl;
  return 0;
}
