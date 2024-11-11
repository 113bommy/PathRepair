#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    int a;
    int f[51] = {0};
    for (int i = 0; i < 2 * n; i++) {
      cin >> a;
      if (f[a] == 0) {
        f[a]++;
        cout << a << " ";
      }
    }
    std::cout << "\n";
  }
  return 0;
}
