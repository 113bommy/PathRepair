#include <bits/stdc++.h>
using namespace std;
int func(int a, int b, int c) {
  if (a > b + c && b > a + c && c > a + b) {
    return (1);
  }
  return (0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c;
  cin >> a >> b >> c;
  int x = min(a, min(b, c));
  int z = max(a, max(b, c));
  int y = a + b + c - x - z;
  long long int ans;
  if (z < x + y) {
    ans = 0;
  } else {
    ans = c - a - b + 1;
  }
  cout << ans;
  return (0);
}
