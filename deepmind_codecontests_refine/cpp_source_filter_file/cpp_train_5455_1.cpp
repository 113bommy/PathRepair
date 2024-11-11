#include <bits/stdc++.h>
using namespace std;
int compute(int n, int s) {
  if (n < s) {
    return n;
  }
  int rem = n % s;
  if (rem == 0) {
    return n / s;
  }
  return rem * (n / s + 1);
}
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  long long horizontal = (long long)compute(n, s);
  long long vertical = (long long)compute(m, s);
  cout << horizontal * vertical << endl;
  return 0;
}
