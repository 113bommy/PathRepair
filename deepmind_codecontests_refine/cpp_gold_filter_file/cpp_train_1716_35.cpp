#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c, hr, hb, wr, wb;
  cin >> c >> hr >> hb >> wr >> wb;
  long long l = 0, r = c / wb, ans = 0;
  for (long long i = l; i <= min(r, (long long)1e5); i++)
    ans = max(ans, i * hb + ((c - wb * i) / wr) * hr);
  r = c / wr;
  for (long long i = l; i <= min(r, (long long)1e5); i++)
    ans = max(ans, i * hr + ((c - wr * i) / wb) * hb);
  cout << ans;
  return 0;
}
