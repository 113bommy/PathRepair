#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
vector<int> digitos(long long n, int dig) {
  vector<int> res;
  while (n > 0) {
    res.push_back(n % 2);
    n /= 2;
  }
  while (res.size() < dig) res.push_back(0);
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int actualAnd[25];
    memset(actualAnd, 0, sizeof(actualAnd));
    set<int> res;
    for (int i = 0; i < n; i++) {
      vector<int> dig = digitos(a[i], 25);
      for (int j = 0; j < 25; j++) {
        if (dig[j] == 0) {
          actualAnd[j] |= a[i];
          res.insert(actualAnd[j]);
        } else {
          actualAnd[j] = 0;
        }
      }
    }
    cout << res.size() << endl;
  }
  return 0;
}
