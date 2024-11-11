#include <bits/stdc++.h>
using namespace std;
long long fexp(int b, int x) {
  long long res = 1;
  while (x > 0) {
    if (x % 2 == 1) res = res * b;
    b = b * b;
    x /= 2;
  }
  return res;
}
long long sh[61];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    long long x;
    cin >> x;
    int lv = log2(x);
    if (t == 1) {
      long long k;
      cin >> k;
      sh[lv] += k;
    } else if (t == 2) {
      long long k;
      cin >> k;
      long long ex = 1;
      for (long long i = 0; i < 61 - lv; ++i) {
        sh[lv + i] += ex * k;
        ex *= 2;
      }
    } else {
      long long st = fexp(2, lv);
      while (1) {
        cout << x << " ";
        if (x == 1) {
          cout << '\n';
          break;
        }
        long long now = st + ((x + sh[lv]) & (st - 1));
        long long p_orig = now / 2;
        long long p_now = st / 2 + ((p_orig - sh[lv - 1]) & (st / 2 - 1));
        x = p_now;
        lv--;
        st /= 2;
      }
    }
  }
  return 0;
}
