#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (b == 0 ? a : (gcd(b, b % a))); }
int main() {
  int n, m;
  cin >> n >> m;
  cout << gcd(n - 1, m - 1) + 1 << endl;
}
