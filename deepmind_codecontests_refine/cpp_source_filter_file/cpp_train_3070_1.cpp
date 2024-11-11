#include <bits/stdc++.h>
using namespace std;
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int minn = 1e5 + 9;
const int N = 5e3 + 123;
const int NN = 5e5 + 123;
const int PRI = 555557;
const int pri = 997;
int a[200200], sum, ans;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  string a, b;
  cin >> a >> b;
  int cur = 0;
  for (int i = 0; i < (int)(a.size()); i++) {
    if (a[i] != b[i]) cur++;
  }
  if (cur % 2) {
    cout << "Impossible";
    return 0;
  }
  bool ok = 0;
  for (int i = 0; i < (int)(a.size()); i++) {
    if (a[i] == b[i]) {
      cout << a[i];
    } else if (ok) {
      cout << b[i];
      ok = 0;
    } else {
      cout << a[i];
      ok = 1;
    }
  }
}
