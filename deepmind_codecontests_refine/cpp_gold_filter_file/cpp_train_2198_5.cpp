#include <bits/stdc++.h>
using namespace std;
long long count(long long x) {
  unsigned long long count = 0;
  while (x) {
    if ((x & 1)) count++;
    x >>= 1;
  }
  return count;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a;
    cin >> a;
    long long c = count(a);
    cout << (1 << c) << '\n';
  }
  return 0;
}
