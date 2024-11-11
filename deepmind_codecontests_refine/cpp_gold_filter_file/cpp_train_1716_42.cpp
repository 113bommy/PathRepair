#include <bits/stdc++.h>
using namespace std;
long long int c, hr, hb, wr, wb;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> c >> hr >> hb >> wr >> wb;
  long long int ans = 0;
  if (wb * wb >= c) {
    for (long long int i = 0; i * wb <= c; ++i) {
      ans = max(ans, i * hb + (c - i * wb) / wr * hr);
    }
    cout << ans << '\n';
    return 0;
  }
  if (wr * wr >= c) {
    for (long long int i = 0; i * wr <= c; ++i) {
      ans = max(ans, i * hr + (c - i * wr) / wb * hb);
    }
    cout << ans << '\n';
    return 0;
  }
  if (hr * wb <= hb * wr) {
    swap(hb, hr);
    swap(wb, wr);
  }
  for (long long int i = 0; i <= wr && i * wb <= c; ++i) {
    ans = max(ans, i * hb + (c - i * wb) / wr * hr);
  }
  cout << ans << '\n';
  return 0;
}
