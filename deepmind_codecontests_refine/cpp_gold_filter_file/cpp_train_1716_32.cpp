#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c, hr, hb, wr, wb;
  cin >> c >> hr >> hb >> wr >> wb;
  long long ans = 0;
  long long t = max(0LL, c / (wr * wb) - 2LL);
  if (wb * hr >= wr * hb)
    ans += t * hr * wb;
  else
    ans += t * hb * wr;
  c -= t * wr * wb;
  long long best = 0;
  if (wb > wr) {
    swap(wb, wr);
    swap(hb, hr);
  }
  for (long long i = 0; i * wr <= c; i++) {
    long long r = (c - i * wr) / wb;
    best = max(best, r * hb + i * hr);
  }
  ans += best;
  cout << ans << endl;
  return 0;
}
