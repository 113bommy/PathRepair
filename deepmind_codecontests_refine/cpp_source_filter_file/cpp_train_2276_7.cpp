#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, ct = 0, t;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (!(a < t && t < b)) ct++;
  }
  cout << ct << endl;
}
