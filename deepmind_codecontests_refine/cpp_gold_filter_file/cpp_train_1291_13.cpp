#include <bits/stdc++.h>
using namespace std;
int main() {
  long long r, h, res;
  cin >> r >> h;
  res = (h / r) * 2;
  if (4 * (h - (res / 2) * r) * (h - (res / 2) * r) >= 3 * r * r)
    res += 3;
  else if (2 * (h - (res / 2) * r) >= r)
    res += 2;
  else
    ++res;
  cout << res;
  return 0;
}
