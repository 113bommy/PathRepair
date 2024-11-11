#include <bits/stdc++.h>
using namespace std;
long long distance(long long x1, long long y1, long long x2, long long y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main() {
  long long n, k, d, x, y, tot = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      tot++;
    }
  }
  if (tot <= k)
    cout << "no solution" << endl;
  else {
    for (int i = 0; i < n; i++) {
      cout << 0 << " " << i + 12345 << endl;
    }
  }
  return 0;
}
