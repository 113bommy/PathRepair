#include <bits/stdc++.h>
using namespace std;
int main() {
  long long b[6];
  int n;
  cin >> n;
  long long a1, a2, a3;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> b[j];
    }
    a1 = b[0];
    a2 = b[1];
    if (b[2] == b[1] + b[0])
      a3 = b[3];
    else
      a3 = b[2];
    cout << a3 << " " << a2 << " " << a1;
    if (i != n - 1) cout << "\n";
  }
  return 0;
}
