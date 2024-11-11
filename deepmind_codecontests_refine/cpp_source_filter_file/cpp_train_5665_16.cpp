#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return (a + b);
  if (a > b) return (gcd(a % b, b));
  return (gcd(a, b % a));
}
int sqr(int x) { return (x * x); }
void out() {
  std::cout << "NO\n";
  exit(0);
}
using namespace std;
int n, m, a, b, sa = 0, sb = 0;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  bool odd_pair = false;
  for (int i = 0; i < (int)(n); i++) {
    cin >> a >> b;
    if (a % 2 != b % 2) odd_pair = true;
    sa += a;
    sb += b;
  }
  if (sa % 2 + sb % 2 == 0)
    cout << "0";
  else if (sa % 2 != sb % 2 && odd_pair && n != 1)
    cout << "1";
  else
    cout << -1;
  cout << endl;
  return 0;
  ;
}
