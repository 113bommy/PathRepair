#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-11;
const int maxn = 1e5 + 9;
const double pi = 3.14159265358979323846264;
const int inf = 1e9;
const int mod = 1e9 + 7;
long long op[maxn];
int main() {
  ios::sync_with_stdio(false);
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  for (long long i = 1; i < maxn; ++i) op[i] = (i - 1) * i / 2;
  int pos;
  if (a) {
    pos = lower_bound(op, op + maxn, a) - op;
    if (op[pos] != a)
      a = -1;
    else
      a = pos;
  } else {
    if (b || c)
      a = 1;
    else
      a = 0;
  }
  if (d) {
    pos = lower_bound(op, op + maxn, d) - op;
    if (op[pos] != d)
      d = -1;
    else
      d = pos;
  } else {
    if (b || c)
      d = 1;
    else
      d = 0;
  }
  if (a < 0 || d < 0 || b + c != a * d) {
    cout << "Impossible";
    return 0;
  }
  if (!a && !d) {
    cout << 0;
    return 0;
  } else if (!a) {
    for (int i = 0; i < d; ++i) cout << 1;
    return 0;
  } else if (!d) {
    for (int i = 0; i < a; ++i) cout << 0;
    return 0;
  }
  long long tb = b / a, mb = b % a;
  long long tc = c / a, mc = c % a;
  for (int i = 0; i < tc; ++i) cout << 1;
  if (mb) {
    for (int i = 0; i < mb; ++i) cout << 0;
    cout << 1;
    for (int i = mb; i < a; ++i) cout << 0;
  } else {
    for (int i = 0; i < a; ++i) cout << 0;
  }
  for (int i = 0; i < tb; ++i) cout << 1;
  return 0;
}
