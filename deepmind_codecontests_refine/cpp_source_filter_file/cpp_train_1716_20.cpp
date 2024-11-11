#include <bits/stdc++.h>
using namespace std;
long long c, hr, hb, wr, wb;
int main() {
  cin >> c >> hr >> hb >> wr >> wb;
  long long i, mx = 0, mxi;
  for (i = 0; i <= c / wr; i += 1000)
    if (i * hr + ((c - i * wr) / wb) * hb > mx) {
      mx = i * hr + ((c - i * wr) / wb) * hb;
      mxi = i;
    }
  for (i = max((long long)0, mxi - 1005); i <= min(c / wr, mxi + 1005); i++)
    if (i * hr + ((c - i * wr) / wb) * hb > mx) {
      mx = i * hr + ((c - i * wr) / wb) * hb;
      mxi = i;
    }
  cout << mx << endl;
  return 0;
}
