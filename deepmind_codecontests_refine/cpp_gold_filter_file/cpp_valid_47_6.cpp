#include <bits/stdc++.h>
using namespace std;
long long ask1(long long a, long long b) {
  cout << "and " << a << " " << b << "\n";
  long long n;
  cin >> n;
  return n;
}
long long ask2(long long a, long long b) {
  cout << "or " << a << " " << b << "\n";
  long long n;
  cin >> n;
  return n;
}
int32_t main() {
  long long T = 1;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    long long a12 = ask1(1, 2);
    long long o12 = ask2(1, 2);
    long long a23 = ask1(2, 3);
    long long o23 = ask2(2, 3);
    long long a13 = ask1(1, 3);
    long long o13 = ask2(1, 3);
    long long o123 = o12 | o23;
    long long a123 = a12 & a23;
    long long a = (o123 - o23 + a12 + a13 - a123);
    long long b = o12 - (a - a12);
    long long c = o13 - (a - a13);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    for (long long i = 3; i < n; i++) {
      long long ba = ask1(1, i + 1);
      long long bo = ask2(1, i + 1);
      v[i] = bo - (a - ba);
    }
    sort(v.begin(), v.end());
    cout << "finish " << v[k - 1] << "\n";
  }
}
