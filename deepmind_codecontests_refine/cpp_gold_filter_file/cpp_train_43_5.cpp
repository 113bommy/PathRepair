#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int total = 0;
  for (int i = 0; i <= c; i++) {
    for (int j = 0; j <= b; j++) {
      if (i * 2 + j > n) break;
      int l = (n - (2 * i + j));
      if (2 * l <= a) total++;
    }
  }
  cout << total << endl;
  return 0;
}
