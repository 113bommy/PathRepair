#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  unsigned long long tt;
  cin >> tt;
  while (tt--) {
    unsigned long long a, b, m;
    cin >> a >> b >> m;
    if (a == b) {
      cout << "1 " << a << '\n';
      continue;
    } else if (b - a <= m) {
      cout << "2 " << a << ' ' << b << '\n';
      continue;
    } else {
      unsigned long long i, j;
      unsigned long long l = 0;
      unsigned long long r = log2((unsigned long long)1e14) - 2;
      unsigned long long exp = 1;
      bool ok = 0;
      for (i = l; i <= r + 1; i++) {
        if (b >= exp * (a + 1) && b <= exp * (a + m)) {
          ok = 1;
          break;
        }
        exp *= 2;
      }
      if (ok) {
        vector<unsigned long long> r;
        r.push_back(b);
        bool f = 0;
        for (j = i; j > 0; j--) {
          unsigned long long t = r.back();
          if (t % 2) {
            if (!f)
              t -= t % 2;
            else
              t += t % 2;
            f = !f;
          }
          r.push_back(t / 2);
        }
        r.push_back(a);
        reverse(r.begin(), r.end());
        cout << i + 2 << ' ';
        for (auto x : r) {
          cout << x << ' ';
        }
        cout << '\n';
      } else {
        cout << "-1\n";
      }
    }
  }
}
