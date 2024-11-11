#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  long long t;
  cin >> t;
  while (t--) {
    long long n, g = 0, s = 0, b = 0, i, gidx, bidx, cidx;
    cin >> n;
    int flag = 0;
    long long p[n];
    for (i = 0; i < n; i++) {
      cin >> p[i];
    }
    long long m = n / 2;
    cidx = m;
    cidx--;
    while (p[cidx + 1] == p[cidx]) {
      cidx--;
      if (cidx < 4) {
        cout << "0 0 0"
             << "\n";
        flag = 1;
        break;
      }
    }
    if (flag) break;
    gidx = 1;
    while (p[gidx] == p[gidx - 1]) {
      gidx++;
      if (gidx >= cidx) {
        cout << "0 0 0"
             << "\n";
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    bidx = 2 * gidx + 1;
    while (p[bidx] == p[bidx - 1]) {
      bidx++;
      if (bidx >= cidx) {
        cout << "0 0 0"
             << "\n";
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    g = gidx;
    b = bidx - gidx;
    s = cidx - bidx + 1;
    if (g == 0 || b == 0 || s <= 0 || g >= s)
      cout << "0 0 0"
           << "\n";
    else
      cout << g << " " << b << " " << s << "\n";
  }
  return 0;
}
