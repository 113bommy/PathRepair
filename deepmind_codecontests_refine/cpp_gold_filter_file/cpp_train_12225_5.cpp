#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long p, x;
  cin >> p >> x;
  int digarr[p];
  int digit = 1;
  while (digit < 10) {
    digarr[0] = digit;
    int rem = 0;
    for (int i = 1; i < p; i++) {
      digarr[i] = ((digarr[i - 1] * x) + rem) % 10;
      rem = (rem + x * digarr[i - 1]) / 10;
    }
    if (digarr[p - 1] != 0 and digarr[0] == (x * digarr[p - 1] + rem)) {
      for (int i = p - 1; i >= 0; i--) {
        cout << digarr[i];
      }
      return 0;
    }
    digit++;
  }
  cout << "Impossible";
  return 0;
}
