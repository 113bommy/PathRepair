#include <bits/stdc++.h>
using namespace std;
long long n;
double p;
double myfunc(long long n, long long m) {
  if (n < m) return 0;
  double ret = 1;
  for (int i = 0; i < m; ++i) {
    ret *= n - i;
    ret /= i + 1;
  }
  return ret;
}
double mypr(long long n, long long m, int i) {
  return myfunc(m, i) * myfunc(n - m, 3 - i) / myfunc(n, 3);
}
double shit(long long n, long long m, int i) {
  double pp = mypr(n, m, i);
  if (i == 0) {
    return pp * 0;
  } else if (i == 1) {
    return pp * 0.5;
  } else if (i == 2) {
    return pp * 1;
  } else {
    return pp * 1;
  }
}
int fuck() {
  if (p < 1e-6) return 0;
  for (long long m = 1; m <= n; ++m) {
    double temp = 0;
    for (int i = 0; i <= 3 && i <= m; ++i) {
      temp += shit(n, m, i);
    }
    if (temp >= p) return m;
  }
}
int main() {
  cin >> n >> p;
  cout << fuck() << endl;
}
