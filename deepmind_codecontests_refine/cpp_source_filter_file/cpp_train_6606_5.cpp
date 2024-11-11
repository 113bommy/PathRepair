#include <bits/stdc++.h>
using namespace std;
long long fact(long long n) {
  long long mm = 1;
  for (long long i = 1; i <= n; i++) {
    mm *= i;
  }
  return mm;
}
long long ncr(long long n, long long r) {
  long long n1 = fact(n);
  long long n2 = fact(r);
  long long n3 = fact(n - r);
  return (((n1 / n2) * n3));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s1, s2;
  cin >> s1;
  cin >> s2;
  double prob;
  long long pl = 0, ne = 0;
  for (auto ch : s1) {
    if (ch == '+')
      pl++;
    else
      ne++;
  }
  long long pl2 = 0, ne2 = 0, dn = 0;
  for (auto ch : s2) {
    if (ch == '+')
      pl2++;
    else if (ch == '-')
      ne2++;
    else
      dn++;
  }
  long long pr = pl - pl2;
  long long nr = ne - ne2;
  if (pr < 0 || nr < 0) {
    cout << "0.000000000000\n";
    return 0;
  }
  long long tt = (1ll << dn);
  long long rq = ncr(dn, pr);
  prob = (rq * 1.0) / tt;
  cout << fixed << setprecision(9) << prob;
}
