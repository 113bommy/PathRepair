#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, n;
  cin >> x >> y >> n;
  long double diff = (int)1e9;
  pair<int, int> ans;
  for (int i = 1; i <= n; i++) {
    int a = (int)(((long double)x / y) * i);
    long double d = abs(((long double)x / y) - ((long double)a / i));
    if (diff > d) {
      ans = make_pair(a, i);
      diff = d;
    }
    d = abs(((long double)x / y) - ((long double)(a + 1) / i));
    if (diff > d) {
      ans = make_pair(a + 1, i);
      diff = d;
    }
  }
  int a = ans.first, b = ans.second;
  cout << a << "/" << b;
  return 0;
}
