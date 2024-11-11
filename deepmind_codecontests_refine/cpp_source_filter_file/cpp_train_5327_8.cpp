#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int nn;
  cin >> nn;
  while (nn--) {
    long long int n, s, t;
    cin >> n >> s >> t;
    if (s == n || t == n) {
      cout << "1" << endl;
    } else {
      long long int y = max(s, t);
      long long int x = min(s, t);
      long long int p = n - y;
      long long int common = x - p;
      long long int r = y - common;
      cout << r + 1 << endl;
    }
  }
}
