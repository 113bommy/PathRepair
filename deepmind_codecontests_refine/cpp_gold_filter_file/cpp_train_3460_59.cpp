#include <bits/stdc++.h>
using namespace std;
void quick() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
}
void readFromText() {}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int MX = 2e5;
int freq[MX + 1];
int freqN[MX + 1];
int main() {
  quick();
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << b << " " << c << " " << c << '\n';
  }
  return 0;
}
unsigned long long pow(long long base, long long power) {
  if (power == 0) return 1;
  if (power == 1) return base;
  unsigned long long ans = pow(base, power / 2);
  ans *= ans;
  if (power & 1) return ans * base;
  return ans;
}
