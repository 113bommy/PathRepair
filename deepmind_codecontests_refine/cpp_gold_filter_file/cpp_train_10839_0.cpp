#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long a, b, k;
    cin >> a >> b >> k;
    cout << (k / 2) * (a - b) + (k % 2) * a << endl;
  }
}
