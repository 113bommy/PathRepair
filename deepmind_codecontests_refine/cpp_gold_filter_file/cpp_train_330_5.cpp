#include <bits/stdc++.h>
using namespace std;
const long long N = 400100;
long long a[N];
pair<long long, long long> b[N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long q, n;
  cin >> q;
  while (q--) {
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    if (n < 6) {
      cout << "0 0 0\n";
      continue;
    }
    long long last, k, g, s, bb;
    last = a[1];
    b[0].first = 1;
    b[0].second = 1;
    k = 0;
    g = s = bb = 0;
    for (long long i = 2; i <= n; ++i) {
      if (a[i] != last) {
        last = a[i];
        k++;
        b[k].first = b[k].second = i;
      } else {
        b[k].second = i;
      }
    }
    g = b[0].second - b[0].first + 1;
    for (long long i = 1; i < k; ++i) {
      if (b[i].second > (n / 2)) break;
      if (s <= g) {
        s += b[i].second - b[i].first + 1;
      } else {
        bb += b[i].second - b[i].first + 1;
      }
    }
    if (g >= s || g >= bb || g == 0 || bb == 0 || s == 0) {
      cout << "0 0 0\n";
    } else {
      cout << g << " " << s << " " << bb << "\n";
    }
  }
  return 0;
}
