#include <bits/stdc++.h>
using namespace std;
long long n, z, a, b, q;
long long BIT[2][400001];
long long sum(long long c, long long i) {
  long long k = 0;
  while (i > 0) {
    k += BIT[c][i];
    i -= i & -i;
  }
  return k;
}
void add(long long c, long long i, long long k) {
  while (i < 400001) {
    BIT[c][i] += k;
    i += i & -i;
  }
}
long long orders[400001];
int main() {
  cin >> n >> z >> a >> b >> q;
  for (long long i = 0; i < 400001; i++) {
    orders[i] = 0;
    BIT[0][i] = BIT[1][i] = 0;
  }
  for (long long i = 0; i < q; i++) {
    long long ty;
    cin >> ty;
    if (ty == 1) {
      long long day, ord;
      cin >> day >> ord;
      add(0, day, min(b, ord + orders[day]) - min(b, orders[day]));
      add(1, day, min(a, ord + orders[day]) - min(a, orders[day]));
      orders[day] += ord;
    } else if (ty == 2) {
      long long p;
      cin >> p;
      cout << sum(0, p - 1) - sum(1, p + z - 1) + sum(1, n) << endl;
    }
  }
}
