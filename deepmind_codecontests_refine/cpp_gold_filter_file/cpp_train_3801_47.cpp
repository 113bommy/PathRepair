#include <bits/stdc++.h>
using namespace std;
int main() {
  set<pair<long long, long long> > S;
  long long x;
  cin >> x;
  S.insert(make_pair(1, x));
  S.insert(make_pair(x, 1));
  for (long long n = 2; n * n * n <= 8 * x; ++n) {
    if ((6 * x + n * n * n - n) % (3 * n * (n + 1))) continue;
    long long m = (6 * x + n * n * n - n) / (3 * n * (n + 1));
    if (n > m) break;
    if (-n * n * n + 3 * n * n * m + 3 * n * m + n == 6 * x) {
      S.insert(make_pair(n, m));
      S.insert(make_pair(m, n));
    }
  }
  cout << S.size() << endl;
  for (set<pair<long long, long long> >::iterator it = S.begin(); it != S.end();
       ++it)
    cout << it->first << " " << it->second << endl;
  return 0;
}
