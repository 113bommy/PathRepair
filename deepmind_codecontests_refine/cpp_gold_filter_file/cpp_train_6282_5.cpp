#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return (a ? gcd(b % a, a) : b); }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n + 1);
  for (int i = (0); i < (n + 1); ++i) {
    cin >> a[i];
  }
  vector<int> b(m + 1);
  for (int i = (0); i < (m + 1); ++i) {
    cin >> b[i];
  }
  if (n > m) {
    if (a[0] * b[0] < 0) cout << "-";
    cout << "Infinity\n";
    return 0;
  }
  if (n < m) {
    cout << "0/1\n";
    return 0;
  }
  int A = a[0];
  int B = b[0];
  bool minus = false;
  if (A * B < 0) minus = true;
  A = abs(A);
  B = abs(B);
  int g = gcd(A, B);
  A /= g;
  B /= g;
  if (minus) cout << "-";
  cout << A << "/" << B << endl;
  return 0;
}
