#include <bits/stdc++.h>
using namespace std;
long long c, hr, hb, wr, wb;
inline long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  cin >> c >> hr >> hb >> wr >> wb;
  long long ans = 0;
  int t = c / wr;
  for (int i = 0; i <= t && i < 100000; i++) {
    ans = max(ans, i * hr + (c - i * wr) / wb * hb);
  }
  swap(hr, hb);
  swap(wr, wb);
  t = c / wr;
  for (int i = 0; i <= t && i < 100000; i++) {
    ans = max(ans, i * hr + (c - i * wr) / wb * hb);
  }
  cout << ans << endl;
  return 0;
}
