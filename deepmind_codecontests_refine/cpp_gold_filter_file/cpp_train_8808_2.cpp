#include <bits/stdc++.h>
using namespace std;
map<vector<long long>, long long> df;
struct fen {
  long long n, m;
  vector<vector<long long>> d;
  fen(long long n, long long m) {
    this->n = n;
    this->m = m;
    d.resize(n + 13);
    for (long long i = 0; i <= n; i++) d[i].resize(m + 13);
  }
  void sumupdv(long long x, long long y, long long z) {
    for (long long a = x; a >= 0; a = (a & (a + 1)) - 1)
      for (long long b = y; b >= 0; b = (b & (b + 1)) - 1) d[a][b] += z;
  }
  long long value(long long x, long long y) {
    long long sum = 0;
    for (long long i = x; i <= n; i = (i | (i + 1)))
      for (long long j = y; j <= m; j = (j | (j + 1))) sum += d[i][j];
    return sum;
  }
  void sumupd(long long x1, long long y1, long long x2, long long y2,
              long long z) {
    sumupdv(x2, y2, z);
    sumupdv(x1 - 1, y1 - 1, z);
    sumupdv(x2, y1 - 1, -z);
    sumupdv(x1 - 1, y2, -z);
  }
};
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, q;
  cin >> n >> m >> q;
  fen sd(n + 13, m + 13);
  long long h = 7;
  for (long long i = 0; i < q; i++) {
    long long t, x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    if (t == 1) {
      df[{x1, y1, x2, y2}] = h;
      h *= 7;
      if (h < 0) h *= -1;
      sd.sumupd(x1, y1, x2, y2, df[{x1, y1, x2, y2}]);
    }
    if (t == 2) sd.sumupd(x1, y1, x2, y2, -df[{x1, y1, x2, y2}]);
    if (t == 3) {
      long long r1 = sd.value(x1, y1);
      long long r2 = sd.value(x2, y2);
      if (r1 == r2)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}
