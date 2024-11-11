#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const long long int inf = 100000000000000000LL;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);
  srand(23);
  int start = clock();
  long long int c, hr, hb, wr, wb;
  cin >> c >> hr >> hb >> wr >> wb;
  if (hr * wb < hb * wr || hr * wb == hb * wr && wr > wb) {
    swap(hr, hb);
    swap(wr, wb);
  }
  long long int ans = 0;
  int n = c / wr;
  int i = n;
  while (i >= 0) {
    for (int k = 0; k <= min(10000, i);) {
      long long int q = i - k;
      long long int a = q * wr;
      long long int b = c - a;
      long long int j = b / wb;
      long long int h = q * hr + j * hb;
      ans = max(h, ans);
      ++k;
      long long int e = (c - (i - k) * wr) / wb;
      if (e == j) {
        long long int t = (c - (j + 1) * wb) / wr;
        k = i - t;
      }
    }
    i -= 10000;
    if (clock() - start > CLOCKS_PER_SEC * 0.9) break;
  }
  cout << ans;
  return 0;
}
