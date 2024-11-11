#include <bits/stdc++.h>
using namespace std;
long long int maxii(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int minii(long long int a, long long int b) {
  if (a > b) return b;
  return a;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    long long int maxi(-1), maxi2(100000000000);
    for (int i = 0; i < n; ++i) {
      long long int y, c;
      cin >> y >> c;
      maxi = maxii(maxi, y);
      maxi2 = minii(maxi2, c);
    }
    cout << minii(0, abs(maxi - maxi2)) << "\n";
  }
}
