#include <bits/stdc++.h>
using namespace std;
int cnt, h;
bool f = true;
int main() {
  long long s, x;
  cin >> s >> x;
  h = sizeof(long long) * 8 - __builtin_clzll(max(s, x)) - 1;
  for (; h >= 0; h--) {
    if (x & (1LL << h))
      cnt++, s -= (1LL << h);
    else if (s >= (1LL << h + 1))
      s -= (1LL << h + 1), f = false;
  }
  if (s || (cnt < 2 && f))
    cout << 0 << endl;
  else
    cout << (1LL << (cnt)) - f * 2 << endl;
  return 0;
}
