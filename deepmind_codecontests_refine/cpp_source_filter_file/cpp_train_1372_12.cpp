#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int infi = 2147483600;
const long long infl = 1e17;
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < (long long)n; i++) cin >> a[i];
  long long q;
  cin >> q;
  vector<long long> last_buy(n, -1);
  vector<pair<long long, long long> > query(q);
  for (long long i = 0; i < (long long)q; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      long long p, x;
      cin >> p >> x;
      p--;
      query[i] = make_pair(p, x);
    } else {
      long long x;
      cin >> x;
      query[i] = make_pair(-1, x);
    }
  }
  vector<long long> ans(n, 0);
  long long xnow = 0;
  for (long long i = (long long)q - 1; i > (long long)-1; i--) {
    if (query[i].first == -1) {
      xnow = max(xnow, query[i].second);
    } else if (ans[query[i].first] == 0) {
      ans[query[i].first] = max(query[i].second, xnow);
    }
  }
  for (long long i = 0; i < (long long)n; i++) {
    if (ans[i] == 0) {
      cout << max(a[i], xnow) << " ";
    } else {
      cout << ans[i] << " ";
    }
  }
  cout << endl;
}
