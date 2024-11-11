#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const bool DEBUG_ = 0;
const double EPS = 1e-6;
const int MOD = 998244353;
int main() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  string b;
  cin >> b;
  int res = 0;
  for (int i = 0; i < n / 2; i++) {
    vector<int> na(26, 0);
    vector<int> nb(26, 0);
    na[a[i] - 'a']++;
    na[a[n - i - 1] - 'a']++;
    nb[b[n - i - 1] - 'a']++;
    nb[b[i] - 'a']++;
    bool good = true;
    for (int j = 0; j < 26; j++) {
      if (na[j] + nb[j] == 1) {
        good = false;
      }
    }
    if (!good) {
      int nn = 0, ma = 0, mb = 0;
      for (int j = 0; j < 26; j++) {
        if (na[j] + nb[j]) {
          nn++;
        }
        ma = max(ma, na[j]);
        mb = max(mb, nb[j]);
      }
      if (nn == 4) {
        res += 2;
      } else if (nn == 3) {
        if (ma == 1) {
          if (mb == 1) {
            res += 1;
          } else {
            res += 2;
          }
        } else {
          res += 2;
        }
      } else if (nn == 2) {
        res++;
      }
    }
  }
  if (n % 2) {
    res += (a[n / 2] != b[n / 2]);
  }
  cout << res;
  return 0;
}
