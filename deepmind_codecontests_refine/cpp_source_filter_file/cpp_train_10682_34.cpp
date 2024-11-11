#include <bits/stdc++.h>
using namespace std;
void print(long long a) { cout << a << '\t' << '\n'; }
void print(long long a, long long b) { cout << a << '\t' << b << '\t' << '\n'; }
void print(long long a, long long b, long long c) {
  cout << a << '\t' << b << '\t' << c << '\n';
}
void print(long long a, long long b, long long c, long long d) {
  cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}
void print(long long a, long long b, long long c, long long d, long long e) {
  cout << a << '\t' << b << '\t' << c << '\t' << d << '\t' << e << '\n';
}
void MAIN() {
  long long n, k, t;
  cin >> n >> k >> t;
  if (t <= k)
    cout << t;
  else if (t >= k and t <= n)
    cout << k;
  else
    cout << t - n + 1;
}
int32_t main() { MAIN(); }
