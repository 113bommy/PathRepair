#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  float d = (float)s / n;
  if (d < 2)
    cout << "NO";
  else {
    cout << "YES\n";
    for (int i = 0; i < n - 1; ++i) {
      cout << 2 << " ";
    }
    cout << s - 2 * (n - 1) << "\n" << 1;
  }
  return 0;
}
