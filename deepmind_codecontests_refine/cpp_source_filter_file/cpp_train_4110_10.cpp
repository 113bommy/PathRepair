#include <bits/stdc++.h>
using namespace std;
struct _ {
  ios_base::Init i;
  _() {
    cin.sync_with_stdio(0);
    cin.tie(0);
  }
} _;
long long power(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n % 2 == 1) ans *= a;
    a *= a;
    n /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int M, V;
  int temp1, temp2;
  temp1 = 3 * a / 10;
  temp2 = (a - a / 250) * c;
  M = max(temp1, temp2);
  temp1 = 3 * b / 10;
  temp2 = (b - b / 250) * d;
  V = max(temp1, temp2);
  if (M > V)
    cout << "Misha\n";
  else if (M < V)
    cout << "Vasya\n";
  else
    cout << "Tie\n";
  return 0;
}
