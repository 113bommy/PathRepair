#include <bits/stdc++.h>
using namespace std;
int main() {
  long long b, d, s, mx, sm = 0;
  cin >> b >> d >> s;
  mx = max(b, max(s, s));
  if (mx != b) b++;
  if (mx != d) d++;
  if (mx != s) s++;
  sm += mx - b;
  sm += mx - d;
  sm += mx - s;
  cout << sm << endl;
  return 0;
}
