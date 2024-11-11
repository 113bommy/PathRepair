#include <bits/stdc++.h>
using namespace std;
long long int add[2001], sub[2001];
int main() {
  long long int n;
  cin >> n;
  long long int x, y, ans = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> x >> y;
    ans += add[x + y];
    ans += sub[1050 + (x - y)];
    add[x + y]++;
    sub[1050 + (x - y)]++;
  }
  cout << ans << "\n";
}
