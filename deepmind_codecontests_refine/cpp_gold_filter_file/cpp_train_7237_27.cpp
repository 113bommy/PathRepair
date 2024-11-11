#include <bits/stdc++.h>
using namespace std;
int n, a;
int main() {
  cin >> n >> a;
  for (int i = 1; i <= n / 2; i++) {
    int u = 2 * i - 1, d = n - u + 1;
    if (a == u | a == d) {
      cout << i << endl;
      return 0;
    }
  }
}
