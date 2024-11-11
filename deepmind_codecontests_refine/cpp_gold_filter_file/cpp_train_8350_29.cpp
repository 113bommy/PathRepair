#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int A[N], d, n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int h, m;
    cin >> h >> m;
    cout << 60 * (23 - h) + (60 - m) << '\n';
  }
  return 0;
}
