#include <bits/stdc++.h>
using namespace std;
long long c, hi, hb, wi, wb;
int main() {
  cin >> c;
  cin >> hi >> hb >> wi >> wb;
  long long ans = 0;
  for (int i = 0; i < 10000000; i++) {
    if (i * wi <= c) {
      ans = max(ans, i * hi + (((c - (i * hi)) / wb) * hb));
    }
    if (i * wb <= c) {
      ans = max(ans, i * hb + (((c - (i * hb)) / wi) * hi));
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
