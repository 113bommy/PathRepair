#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c, hr, hb, wr, wb, i, o;
  cin >> c >> hr >> hb >> wr >> wb;
  o = c / wr * hr;
  for (i = 1; i * wr <= c && i <= 10000000; i++)
    o = max(o, i * hr + (c - i * wr) / wb * hb);
  for (i = 1; i * wb <= c && i <= 10000000; i++)
    o = max(o, i * hb + (c - i * wb) / wr * hr);
  cout << o << endl;
}
