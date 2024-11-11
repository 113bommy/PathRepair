#include <bits/stdc++.h>
using namespace std;
long long n, x, maxx = 0, ans, sum = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    sum += x;
    maxx = maxx < x ? x : maxx;
  }
  ans = (sum % (n - 1) ? 1 : 0) + sum / (n - 1);
  cout << (maxx > ans ? maxx : ans);
  return 0;
}
