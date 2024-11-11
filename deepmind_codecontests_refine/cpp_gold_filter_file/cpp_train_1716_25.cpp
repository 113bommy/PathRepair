#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c, ha, hb, wa, wb;
  long long ans = 0;
  cin >> c >> ha >> hb >> wa >> wb;
  if (wa > wb) swap(wa, wb), swap(ha, hb);
  if (wb > sqrt(c)) {
    for (int i = 0; i <= c / wb; i++)
      ans = max(ans, i * hb + (c - i * wb) / wa * ha);
  } else {
    if (ha * 1. / wa > (hb * 1. / wb)) swap(wa, wb), swap(ha, hb);
    for (int i = 0; i <= wb; i++)
      ans = max(ans, i * ha + (c - i * wa) / wb * hb);
  }
  cout << ans << endl;
  return 0;
}
