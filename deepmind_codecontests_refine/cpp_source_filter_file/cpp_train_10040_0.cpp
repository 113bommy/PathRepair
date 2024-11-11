#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t, s(0), b(1);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (s + t <= m)
      s += t;
    else {
      b++;
      s = 0;
    }
  }
  cout << b << endl;
  return 0;
}
