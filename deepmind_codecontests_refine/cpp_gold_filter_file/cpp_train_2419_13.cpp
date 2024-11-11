#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    double n, m, s = 0;
    cin >> n >> m;
    s = ceil(n / m);
    cout << (int)(m * s - n) << endl;
  }
}
