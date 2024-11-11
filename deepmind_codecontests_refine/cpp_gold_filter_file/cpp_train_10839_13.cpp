#include <bits/stdc++.h>
using namespace std;
long long a, b, k, t;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> k;
    cout << a * ((k + 1) / 2) - b * (k / 2) << endl;
  }
}
