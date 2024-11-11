#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, 1, -1};
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n - 1), d(n - 1);
  for (int i = (int)(2); i < (int)(n + 1); i++) {
    cout << "and " << 1 << " " << i << endl;
    int x;
    cin >> x;
    c[i - 2] = x;
    cout << "or " << 1 << " " << i << endl;
    int y;
    cin >> y;
    d[i - 2] = y;
  }
  vector<int> a0(31, -1);
  for (int i = (int)(0); i < (int)(31); i++) {
    for (int j = (int)(0); j < (int)(n - 1); j++) {
      if ((c[j] >> i & 1) && (d[j] >> i & 1)) a0[i] = 1;
      if (!(c[j] >> i & 1) && !(d[j] >> i & 1)) a0[i] = 0;
    }
  }
  cout << "and " << 2 << " " << 3 << endl;
  int xx;
  cin >> xx;
  cout << "or " << 2 << " " << 3 << endl;
  int yy;
  cin >> yy;
  for (int i = (int)(0); i < (int)(31); i++) {
    if (a0[i] != -1) continue;
    if ((xx >> i & 1) && (yy >> i & 1)) a0[i] = 0;
    if (!(xx >> i & 1) && !(yy >> i & 1)) a0[i] = 1;
  }
  vector<int> a(n);
  ll now = 1;
  for (int i = (int)(0); i < (int)(31); i++) {
    a[0] += a0[i] * now;
    now *= 2;
  }
  for (int i = (int)(0); i < (int)(n - 1); i++) {
    ll now2 = 1;
    for (int j = (int)(0); j < (int)(31); j++) {
      if (a[0] >> j & 1) {
        if (c[i] >> j & 1) a[i + 1] += now2;
      } else {
        if (d[i] >> j & 1) a[i + 1] += now2;
      }
      now2 *= 2;
    }
  }
  sort(a.begin(), a.end());
  cout << "finish " << a[k - 1] << endl;
}
