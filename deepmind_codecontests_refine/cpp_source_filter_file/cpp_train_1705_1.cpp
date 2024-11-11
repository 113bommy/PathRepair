#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a_, long long b_) {
  if (b_ > a_) swap(b_, a_);
  return (b_ == 0 ? a_ : gcd(b_, a_ % b_));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  n = min(n, m);
  int a = n, b = 0;
  cout << n << "\n";
  for (long long i = 0; i < n + 1; i++) {
    cout << b++ << " " << a-- << "\n";
  }
  return 0;
}
