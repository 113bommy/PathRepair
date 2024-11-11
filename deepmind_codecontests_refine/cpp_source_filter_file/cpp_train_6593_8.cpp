#include <bits/stdc++.h>
using namespace std;
string a, b;
bool wins(char c, char d) {
  if (c == 'R' and d == 'S') {
    return true;
  }
  if (c == 'S' and d == 'P') {
    return true;
  }
  if (c == 'P' and d == 'R') {
    return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n >> a >> b;
  int m = a.size();
  int k = b.size();
  int res = 0;
  int res2 = 0;
  for (int i = 0; i < n; i++) {
    if (wins(a[i % m], b[i % k])) {
      res2++;
    }
    if (wins(b[i % k], a[i % m])) {
      res++;
    }
  }
  res *= n / (m * k);
  res2 *= n / (m * k);
  n = n % (m * k);
  for (int i = 0; i < n; i++) {
    if (wins(a[i % m], b[i % k])) {
      res2++;
    }
    if (wins(b[i % k], a[i % m])) {
      res++;
    }
  }
  cout << res << " " << res2;
  return 0;
}
