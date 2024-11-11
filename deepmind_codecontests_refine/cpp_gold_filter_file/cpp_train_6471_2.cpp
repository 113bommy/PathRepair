#include <bits/stdc++.h>
using namespace std;
string ans;
int n;
string tos(int x) {
  string r;
  while (x) {
    r += ((x % 10) + '0');
    x /= 10;
  }
  reverse(r.begin(), r.end());
  return r;
}
int main() {
  for (int i = 1; i <= 10000; i++) ans += tos(i);
  cin >> n;
  cout << ans[n - 1];
  return 0;
}
