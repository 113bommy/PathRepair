#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  auto start = high_resolution_clock::now();
  int n, m, ans;
  cin >> n >> m;
  int power = pow(2, n);
  if (n >= 27)
    cout << m << "\n";
  else if (pow(2, n) > m)
    cout << m << "\n";
  else if (pow(2, n) < m) {
    ans = m % power;
    cout << ans;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  return 0;
}
