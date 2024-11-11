#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const long long int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
bool get(long long int l, long long int r) {
  cout << l << " " << r << '\n';
  cout.flush();
  string res;
  cin >> res;
  if (l == r && res == "Yes") exit(0);
  if (res == "Bad") exit(0);
  return (res == "Yes");
}
void cp() {
  long long int n, k;
  cin >> n >> k;
  long long int ops = 0;
  long long int lo = 1, hi = n;
  for (ops = 0; ops <= 4500;) {
    while (hi - lo > 4 * k) {
      long long int mid = (lo + hi) / 2;
      if (get(lo, mid)) {
        lo = max(1LL, lo - k);
        hi = min(n, mid + k);
      } else {
        lo = max(1LL, mid + 1 - k);
        hi = min(n, hi + k);
      }
      ops++;
    }
    long long int len = hi - lo + 1;
    long long int num = lo + rand() % len;
    get(num, num);
    ops++;
    lo = max(1LL, lo - k);
    hi = min(n, hi + k);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  srand(time(NULL));
  while (t--) {
    cp();
  }
  return 0;
}
