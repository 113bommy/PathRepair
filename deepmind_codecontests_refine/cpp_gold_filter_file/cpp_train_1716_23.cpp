#include <bits/stdc++.h>
using namespace std;
long long C, wr, wb, hr, hb, ans;
int main() {
  cin >> C >> hr >> hb >> wr >> wb;
  for (int i = 0; i < 1000000; i++) {
    if (i * wr <= C) ans = max(ans, i * hr + (C - i * wr) / wb * hb);
    if (i * wb <= C) ans = max(ans, i * hb + (C - i * wb) / wr * hr);
  }
  cout << ans << endl;
  return 0;
}
