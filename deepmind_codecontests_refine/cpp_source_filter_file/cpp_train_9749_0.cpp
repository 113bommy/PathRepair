#include <bits/stdc++.h>
using namespace std;
int n, a[100001], b[100001], gcd_;
bool cmp(int a, int b) { return a < b; }
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n, cmp);
  int dis = a[n] - a[1];
  for (int i = 1; i <= n; i++) {
    b[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    b[i] = gcd(b[i - 1], b[i]);
  }
  cout << dis / b[n] - n + 1 << endl;
  return 0;
}
