#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
int rev(int x) {
  for (int j = 0; j < 4; j++) {
    int k = 7 - j;
    int xj = (x >> j) & 1;
    int xk = (x >> k) & 1;
    x = x ^ (xj << j) ^ (xk << k) ^ (xj << k) ^ (xk << j);
  }
  return x;
}
int main() {
  string s;
  getline(cin, s);
  s = '\0' + s;
  int n = s.size();
  for (int i = 1; i < n; i++) {
    int x = (-rev(s[i]) + rev(s[i - 1])) & 255;
    cout << x << '\n';
  }
  return 0;
}
