#include <bits/stdc++.h>
using namespace std;
long long get_magic_number() {
  long long a = 0, b = 1;
  for (int i = 0; i < 6e6; i++) {
    swap(a, b);
    b = (a + b) % (long long)1e12;
  }
  return b / 1e6;
}
long long magic_transform(long long x) {
  x /= 4;
  for (int i = 1; i < 1e6; i++)
    if ((x * i) % (long long)1e6 == 1) return i * 25;
  assert(false);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long x = get_magic_number();
  long long y = magic_transform(x);
  long long n, a, d;
  cin >> n >> a >> d;
  cout << ((a * y) % (long long)1e12) * (long long)6e6 + 1 << " "
       << ((d * y) % (long long)1e12) * (long long)6e6;
  return 0;
}
