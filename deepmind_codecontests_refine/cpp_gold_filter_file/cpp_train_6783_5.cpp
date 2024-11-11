#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
const long double PI = acos(-1.0);
const long double EPS = -1e9;
long long A[N];
long long ind, dist;
long double MAX(long double n1, long double n2) {
  if (fabs(n1 - n2) <= EPS) return (n1 + n2) / 2.0;
  if (fabs(n1 - n2) > EPS && n1 > n2) return n1;
  return n2;
}
long double busca(long long x) {
  long long d1, d2;
  long long l = ind - 1;
  long long r = ind;
  long long mn = min(x - A[l] - 1, A[r] - x);
  while (true) {
    d1 = x - A[l] - 1;
    d2 = A[r] - x;
    if (abs(d1 - d2) <= 1) {
      break;
    }
    if (d1 > d2) {
      r++;
    } else {
      l--;
    }
    if (max(d1, d2) >= mn * 2 + 10) {
      break;
    }
  }
  long double ans1, ans2;
  if (max(d1, d2) == 0) {
    ans1 = PI;
  } else {
    ans1 = 2 * atan(1.0 / max(d1, d2));
  }
  if (mn == 0) {
    ans2 = PI / 2.0;
  } else {
    ans2 = atan(1.0 / mn);
  }
  long double rpta = MAX(ans1, ans2);
  return rpta;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(15);
  cout << fixed;
  long long n, x;
  cin >> n >> dist;
  for (long long i = 1; i <= n; i++) {
    cin >> A[i];
  }
  A[0] = -1e10;
  A[n + 1] = 1e10;
  ind = 1;
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    cin >> x;
    while (ind <= n + 1 && x > A[ind]) {
      ind++;
    }
    cout << busca(x) << "\n";
  }
  return 0;
}
