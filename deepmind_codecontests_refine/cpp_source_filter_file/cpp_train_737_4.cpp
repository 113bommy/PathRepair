#include <bits/stdc++.h>
using namespace std;
const int mxvl = 1e2 + 12;
int main() {
  long long n;
  cin >> n;
  long long mx = 0;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if (a > mx + 1) {
      cout << i + 1;
      return 0;
    }
    mx = max(mx, a);
  }
  cout << -1;
}
