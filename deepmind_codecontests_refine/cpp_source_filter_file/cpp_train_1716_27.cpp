#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  long long c, hr, hb, wr, wb;
  cin >> c >> hr >> hb >> wr >> wb;
  long long res = -1;
  if (sqrt(max(wr, wb)) > sqrt(c)) {
    if (wr > wb) {
      swap(hr, hb);
      swap(wr, wb);
    }
    for (int i = 0; i <= (c / wb); ++i) {
      long long tmp = c - i * wb;
      long long j = tmp / wr;
      res = max(res, i * hb + j * hr);
    }
  } else {
    if (hr * wb > hb * wr) {
      swap(hr, hb);
      swap(wr, wb);
    }
    for (int i = 0; i <= wb; ++i) {
      long long tmp = c - i * wr;
      long long j = tmp / wb;
      res = max(res, i * hr + j * hb);
    }
  }
  cout << res << endl;
  return 0;
}
