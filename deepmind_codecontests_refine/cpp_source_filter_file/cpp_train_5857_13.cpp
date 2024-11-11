#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, r, a;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> r;
    if (r > n)
      a = (n * (n - 1)) / 2 + 1;
    else
      a = (r * (r + 1)) / 2;
    cout << a << endl;
  }
}
