#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  int n, k;
  cin >> n >> k;
  int d = 0;
  while (n--) {
    int x;
    cin >> x;
    d = gcd(x, d);
  }
  bool b[k];
  int cnt = 0;
  long long sum = d;
  memset(b, 0, sizeof(b));
  for (int i = 0; i < k; i++) {
    if (b[sum % k] == 0) cnt++, b[sum % k] = 1;
    sum += d;
  }
  cout << cnt << endl;
  for (int i = 0; i < k; i++) {
    if (b[i] == 1) cout << i << " ";
  }
  return 0;
}
