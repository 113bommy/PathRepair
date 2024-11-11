#include <bits/stdc++.h>
using namespace std;
long long maxLL(long long a, long long b) { return (a > b ? a : b); }
long long minLL(long long a, long long b) { return (a < b ? a : b); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int v[] = {a, b, c, d};
  int* max;
  max = std::max_element(v, v + 4);
  if (*max - a) cout << *max - a << " ";
  if (*max - b) cout << *max - b << " ";
  if (*max - c) cout << *max - c << " ";
  if (*max - d) cout << *max - d << " ";
  return 0;
}
