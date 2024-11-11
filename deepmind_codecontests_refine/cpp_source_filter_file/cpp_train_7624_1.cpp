#include <bits/stdc++.h>
using namespace std;
const int max_size = 1111;
int main() {
  int n = 0;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (2 * min(a, b) < max(a, b))
      cout << max(a, b) * max(a, b) << endl;
    else
      cout << 4 * min(a, b) * min(a, b) << endl;
    return 0;
  }
}
