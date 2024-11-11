#include <bits/stdc++.h>
using namespace std;
int gcd1(int a, int b) {
  if (b == 0) return a;
  return gcd1(b, a % b);
}
int main() {
  ios::sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a >> b;
  if (a == 1 || b == 1) {
    for (int i = 0; i < n; i++) cout << i << ' ';
    cout << endl;
    return 0;
  }
  int g = gcd1(a, b);
  if (n % g) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> op;
  int rem = n, now = 1;
  while (1) {
    if (rem % b == 0) {
      while (rem) {
        int j = 1;
        for (int i = 0; i < b; i++) {
          op.push_back(now + j);
          j++;
          j %= b;
        }
        rem -= b;
        now += b;
      }
      break;
    }
    if (rem < a) {
      cout << -1 << endl;
      return 0;
    }
    int j = 1;
    for (int i = 0; i < a; i++) {
      op.push_back(now + j);
      j++;
      j %= a;
    }
    rem -= a;
    now += a;
  }
  for (int i = 0; i < n; i++) {
    cout << op[i] << ' ';
  }
  cout << endl;
  return 0;
};
