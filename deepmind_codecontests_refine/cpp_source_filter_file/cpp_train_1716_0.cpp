#include <bits/stdc++.h>
using namespace std;
long long c, hi, hb, wi, wb;
int main() {
  cin >> c;
  cin >> hi >> hb >> wi >> wb;
  long long ans = 0;
  for (int i = 0; i < 10000; i++) {
    if (i * wi <= c) {
      ans = max(ans, i * hi + (((c - (i * wi)) / wb) * hb));
    }
    if (i * wb <= c) {
      ans = max(ans, i * hb + (((c - (i * wb)) / wi) * hi));
    }
  }
  cout << ans << endl;
  return 0;
}
