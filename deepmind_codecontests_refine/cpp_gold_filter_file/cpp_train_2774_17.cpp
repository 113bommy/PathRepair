#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long n, k, x, type(1), amt, box;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> x;
    if (x * (n / x) > amt) {
      amt = x * (n / x);
      box = n / x;
      type = i;
    }
  }
  cout << type << " " << box << endl;
}
