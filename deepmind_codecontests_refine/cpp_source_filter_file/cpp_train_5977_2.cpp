#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0 || b == 0) return a + b;
  if (a < b) return gcd(b % a, a);
  return (a % b, b);
}
int a[111];
int main() {
  int n;
  cin >> n;
  int g = 0, max = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    g = gcd(g, a[i]);
    if (max < a[i]) max = a[i];
  }
  for (int i = 0; i < n; i++) {
    a[i] /= g;
  }
  max /= g;
  int moves = max - n;
  if (moves % 2)
    cout << "Alice";
  else
    cout << "Bob";
  return 0;
}
