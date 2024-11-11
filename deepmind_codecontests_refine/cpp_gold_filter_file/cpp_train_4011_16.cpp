#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll s, x;
  cin >> s >> x;
  ll diff = (s - x);
  if (diff < 0 || diff % 2 != 0 || (x & (diff / 2)) != 0) {
    cout << 0;
    return 0;
  }
  ll answer = 1;
  while (x) {
    if (x & 1) answer *= 2;
    x = x >> 1;
  }
  if (diff == 0) answer -= 2;
  cout << answer;
  return 0;
}
